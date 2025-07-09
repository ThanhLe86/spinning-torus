# spinning-torus
This repository will store my attempt on the famous graphics programming topic - the spinning torus (some may call it the spinning donut) 


# Implementation documentation (version 1.0)
- Computing points on the main circle (XY plane)
First, we need to define a series of points that lie on a circle in the XY plane. Let this main circle have a radius R and be centered at the origin (0,0,0).

The coordinates of a point (X,Y,Z) on this circle can be calculated using parametric equations, where θ(phi) is the angle from the positive x-axis, ranging from 0 to 2π radians.

    X = Rcos(θ)

    Y = Rsin(θ)

    Z = 0 (since it's on the XY plane)

To get a discrete set of points, we can iterate θ from 0 to 2π with a small step size (e.g., dθ=π/180) (this increment can change)

For each point Pmain​(θ)=(X,Y,0) on this main circle, it will serve as the center for a new, smaller circle.

- Defining smaller circles centered on main circle points

For each point P<sub>main</sub>O(X,Y,0) calculated above, I defined a new circle with radius r. Initially, let's consider this smaller circle also lying in a plane parallel to the XY plane, centered at Pmain​.

The points (x′,y′,z′) on this smaller circle, relative to its center P<sub>main</sub>​, would be:

    x′ = rcos(ϕ)

    y′ = rsin(ϕ)

    z′ = 0

Where ϕ is the angle from the local x'-axis of the smaller circle, ranging from 0 to 2π radians.

To get the absolute coordinates (x<sub>abs</sub>​,y<sub>abs</sub>,z<sub>abs</sub>​) of a point on this smaller circle before rotation, we add the center's coordinates:

x<sub>abs</sub> = X + rcos(ϕ)

y<sub>abs</sub> = Y + rsin(ϕ)

z<sub>abs</sub> = Z + 0 = 0

So, a point on a smaller circle, before rotation, is P<sub>small</sub>​(ϕ)=(X+rcos(ϕ),Y+rsin(ϕ),0).

- Performing the matrix multiplication for rotation in 3D space, the final coordinates for each point on the rotated smaller circles are:

    x<sub>rotated</sub> ​= (X + rcos(ϕ)) × 1 + (Y + rsin(ϕ)) × 0 + 0 × 0 = X+rcos(ϕ)

    y<sub>rotated</sub> = (X + rcos(ϕ)) × 0 + (Y+rsin(ϕ)) × cos(α)+ 0 × (−sin(α)) = (Y+ rsin(ϕ))cos(α)

    z<sub>rotated</sub> = (X+rcos(ϕ)) × 0 + (Y + rsin(ϕ)) × sin(α) + 0 × cos(α) = (Y + rsin(ϕ))sin(α)

So, for each main circle center Pmain​(X,Y,0) and for each point on the smaller circle defined by ϕ, the final 3D coordinates after rotation around the X-axis by angle α are:

x<sub>final</sub> = X + rcos(ϕ)

y<sub>final</sub> = (Y + rsin(ϕ))cos(α)

z<sub>final</sub> = (Y + rsin(ϕ))sin(α)

This process allows you to generate a series of points that form a "tube" or "torus-like" shape, where the smaller circles are oriented based on the rotation around the X-axis.

# In Short:
- **phi**: angle for rotating around the center 
- **theta**: angle for rotating around each point on the main torus circle
- **rotation_angle**: main rotation angle for rotating the entire torus

#### DEVLOG:
**Update 09.07.2025**
It seems that the for loop for iterating through points on a circle doesn't really work, it just prints out a consecutive line of symbols no matter what I do. Further observations must be made.
