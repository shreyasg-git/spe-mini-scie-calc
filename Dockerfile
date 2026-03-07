# syntax=docker/dockerfile:1
FROM ubuntu:22.04

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt,sharing=locked \
    apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata build-essential cmake libncurses-dev libncursesw5-dev unzip curl expect

WORKDIR /app

COPY . .

ENV TERM=xterm-256color

# Mount the build cache so Google Test + Intermediate objects persist between docker builds!
RUN --mount=type=cache,target=/app/build \
    mkdir -p build && cd build && cmake .. && make && \
    cp ./calculator /app/calculator

CMD ["./calculator"]