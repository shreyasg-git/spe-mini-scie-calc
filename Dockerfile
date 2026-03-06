FROM ubuntu:22.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata build-essential cmake libncurses-dev libncursesw5-dev unzip curl expect

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build && cmake .. && make && ctest --output-on-failure

ENV TERM=xterm-256color

CMD ["./build/calculator"]