import numpy as np
# import math
import matplotlib.pyplot as plt

Kdd = 0.1    
Ld = 2.0  # m
Kp = 1.0   
dt = 0.1  # s
L = 2.9   # m

class VehicleState:

    def __init__(self, x=0.0, y=0.0, yaw=0.0, v=0.0):
        self.x = x
        self.y = y
        self.yaw = yaw
        self.v = v


def update(state, a, delta):
    state.x = state.x + state.v * np.cos(state.yaw) * dt
    state.y = state.y + state.v * np.sin(state.yaw) * dt
    state.yaw = state.yaw + state.v / L * np.tan(delta) * dt
    state.v = state.v + a * dt
    return state


# longitudinal control using P controller
def p_control(target, current):
    a = Kp * (target - current)
    return a

# Lateral control using pure pursuit controller
def pure_pursuit_control(state, cx, cy, p_index):

    index = calc_target_index(state, cx, cy)

    if p_index >= index:
        index = p_index

    if index < len(cx):
        tx = cx[index]
        ty = cy[index]
    else:
        tx = cx[-1]
        ty = cy[-1]
        index = len(cx) - 1

    alpha = np.arctan2(ty - state.y, tx - state.x) - state.yaw

    if state.v < 0:  # back
        alpha = np.pi - alpha

    Lf = Kdd * state.v + Ld

    delta = np.arctan2(2.0 * L * np.sin(alpha) / Lf, 1.0)

    return delta, index


def calc_target_index(state, cx, cy):

    # search the closest target point on path w.r.t the initial cx, cy
    dx = [state.x - icx for icx in cx]
    dy = [state.y - icy for icy in cy]

    d = [abs(np.sqrt(idx**2 + idy**2)) for (idx, idy) in zip(dx, dy)]

    index = d.index(min(d))

    L = 0.0
    # Lf = Kdd * state.v + Ld
    Lf = Ld

    while Lf > L and (index + 1) < len(cx):
        dx = cx[index + 1] - cx[index]
        dy = cx[index + 1] - cx[index]
        L += np.sqrt(dx ** 2 + dy ** 2)
        index += 1

    return index


def main():

    #  define path
    cx = np.arange(0, 50, 1)
    cy = [np.sin(ix / 5.0) * ix / 2.0 for ix in cx]

    target_speed = 10.0 / 3.6  # m/s

    # simulation time
    T = 100.0  

    # set vehicle state
    # state.x = 0.0, state.y = -3.0
    # state.yaw = 0.0, state.v = 0.0
    state = VehicleState(x=0.0, y=-3.0, yaw=0.0, v=0.0)

    lastIndex = len(cx) - 1
    time = 0.0

    # init state vector
    x = [state.x]
    y = [state.y]
    yaw = [state.yaw]
    v = [state.v]
    t = [time]

    target_index = calc_target_index(state, cx, cy)

    while T >= time and lastIndex > target_index:

        ai = p_control(target_speed, state.v) # ai = Kp*(target_speed-state.v)

        delta, target_index = pure_pursuit_control(state, cx, cy, target_index)

        state = update(state, ai, delta)

        time = time + dt

        x.append(state.x)
        y.append(state.y)
        yaw.append(state.yaw)
        v.append(state.v)
        t.append(time)

        plt.cla()
        plt.plot(cx, cy, ".r", label="course")
        plt.plot(x, y, "-b", label="trajectory")
        plt.plot(cx[target_index], cy[target_index], "go", label="target")
        plt.axis("equal")
        plt.grid(True)
        plt.title("Speed[km/h]:" + str(state.v * 3.6)[:4])
        plt.pause(0.001)


if __name__ == '__main__':
    main()


