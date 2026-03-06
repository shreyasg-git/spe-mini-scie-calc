FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y build-essential cmake libncurses-dev libncursesw5-dev unzip curl

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build && cmake .. && make && ctest --output-on-failure

ENV TERM=xterm-256color

CMD ["./build/calculator"]