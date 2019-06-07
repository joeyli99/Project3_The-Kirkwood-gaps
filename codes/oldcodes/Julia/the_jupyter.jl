using DifferentialEquations
using Plots
using Printf
using JLD2
pyplot()

const ms, mj = 4π^2, 4π^2/1047
function f(du, u, para, t)
    ujup = u[1:2]
    ua = u[3:4]
    rjup = sum(abs2, ujup)
    Δra = sum(abs2, ua-ujup)
    ra = sum(abs2, ua)
    A = @. [-ms*ujup/(rjup)^(1.5); -ms*ua/(ra)^(1.5)-mj*(ua-ujup)/Δra^(1.5)]
    return A
end

r = rand(1)*1.5.+2.0
ϕ = rand(1)*2π
# r = 2.5
# ϕ = π/2
function simulation(R, Φ)
    after = Float64[]
    for i in 1:length(R)
        r=R[i]
        ϕ=Φ[i]
        du0=[0, sqrt(4π^2/5.4588*(1-0.048912)), -sqrt(4π^2/r)*sin(ϕ), sqrt(4π^2/r)*cos(ϕ)]
        u0=[5.4588, 0, r*cos(ϕ), r*sin(ϕ)]
        tspan=(0.0, 1000.0)
        prob = SecondOrderODEProblem(f, du0, u0, tspan)
        sol = solve(prob,DPRKN12(),reltol=1e-9,abstol=1e-9)
        vx=sol[3,:][end]
        vy=sol[4,:][end]
        x=sol[7,:][end]
        y=sol[8,:][end]
        append!(after, -2π^2/(0.5*(vx^2+vy^2)-ms/sqrt(x^2+y^2)))
        (i%10==0) && (@printf("%i\n", i))
    end
    return after
end

    # du0=[0, sqrt(4π^2/5.4588*(1-0.048912)), -sqrt(4π^2/r)*sin(ϕ), sqrt(4π^2/r)*cos(ϕ)]
    # u0=[5.4588, 0, r*cos(ϕ), r*sin(ϕ)]
    # tspan=(0.0, 1000.0)
    # prob = SecondOrderODEProblem(f, du0, u0, tspan)
    # sol = solve(prob,KahanLi8(),dt=0.01)
    # vx=sol[3, :]
    # vy=sol[4, :]
    # x=sol[7, :]
    # y=sol[8, :]
    # E =@. 0.5*(vx^2+vy^2)-ms/sqrt(x^2+y^2)
    # a = -2π^2 ./E
    # plot(sol.t, a)
#append!(after, sqrt( (sol[7,:][end])^2+(sol[8,:][end])^2) )
@time result = simulation(r,ϕ)
histogram(result, nbins=100)
@save "try_data.jld2" result r
