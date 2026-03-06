Optimizing Docker Build Speed with Caches
Goal Description
Currently, every time a 
.cpp
 file is modified, Docker invalidates the COPY . . layer. This forces CMake to fetch Google Test from GitHub and re-compile the entire test framework from scratch on every run, dragging out Jenkins pipeline durations. We will speed this up massively by persisting the CMake build directory across Docker builds.

Proposed Changes: Docker BuildKit Caches
By leveraging Docker BuildKit's --mount=type=cache feature, we can instruct the Docker daemon to save the build/ directory across multiple container builds. Instead of wiping the dependency setup, make will only recompile the exact 
.cpp
 files you modified that run!

[MODIFY] 
Dockerfile
Specify # syntax=docker/dockerfile:1 at the very top to enable advanced BuildKit directives.
Tell Docker to keep an APT cache: RUN --mount=type=cache,target=/var/cache/apt ... so apt-get runs instantly in the future.
Update the compiling instruction to RUN --mount=type=cache,target=/app/build ....
Important constraint: Contents stored inside a --mount=type=cache are NOT persisted in the final Docker image. Therefore, after make, we will copy the built binary out of the cache mount (cp build/calculator ./calculator) into the actual image layer.
Update the CMD ["./calculator"] to point to the new persisted location.
Verification Plan
Re-build the Docker image the first time (will take normal time).
Tweak a small print statement in 
main.cpp
.
Build the Docker image a second time. It should skip re-downloading Google Test and finish almost instantaneously due to the persistent Object File caches!