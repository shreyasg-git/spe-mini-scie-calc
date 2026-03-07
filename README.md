# Terminal Scientific Calculator

An interactive C++ scientific calculator built with `ncurses` featuring a complete CI/CD pipeline using Docker, Jenkins, Google Test, Expect integration testing, and Ansible Web TTY deployment.

## Developer Setup Guide

If you are a new developer joining the project, here is exactly what you need to install and run the code locally.

### 1. System Requirements (Linux/Ubuntu)
You will need the following tools installed on your host machine to compile and run the source code natively:

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake libncurses-dev unzip curl expect
```

*(Note: We use `libncurses-dev` for the terminal UI, and `expect` for simulating keyboard inputs during integration tests).*

### 2. Building the Project
We use `CMake` as our build system to manage compilation and testing targets.

```bash
# Generate the Makefiles
mkdir build && cd build
cmake ..

# Compile the source code and test binaries
make
```

### 3. Running the App
Once compiled, you can launch the interactive terminal UI from the `build` directory:

```bash
./calculator
```

### 4. Running the Tests
The project features both C++ Unit Tests (via Google Test) and Shell Integration Tests (via Expect). Our CMake setup automatically downloads and links the Google Test framework.

```bash
# From inside the build/ directory
ctest --output-on-failure
```

---

## Architecture Overview

### Structure
*   `src/calculator.cpp`: The decoupled mathematical logic (Model). Functions throw `std::invalid_argument` on invalid mathematical inputs.
*   `src/main.cpp`: The ncurses interactive terminal interface (View/Controller).
*   `tests/test_calculator.cpp`: Google Test suite for isolating and verifying math function behavior.
*   `tests/integration_test.exp`: Expect script that spins up the compiled binary and simulates live keystrokes to ensure the UI flows correctly.

### CI/CD Pipeline (Jenkins)
Pushing to the `dev` branch triggers a Jenkins pipeline defined in `Jenkinsfile` that executes the following stages:
1.  **Build (CMake):** Compiles the code.
2.  **Unit Tests:** Runs the Google Test suite.
3.  **Integration Tests:** Runs the `expect` scripts with a mocked `TERM` environment.
4.  **Build & Push Docker:** Packages the app and pushes `shreyasg28/sci-calc:latest` to DockerHub.
5.  **Deploy (Ansible):** Executes the Ansible playbook to pull the new container and serve it live over the web.

### Web Deployment (Gotty & Ansible)
Because this is an interactive CLI app built on `ncurses`, deploying it as a raw Docker container means users would have to manually SSH or use `docker run -it` locally to use it. 
Instead, we package **Gotty** directly into our Dockerfile. Gotty exposes any terminal CLI application securely over HTTP WebSocket.

Our Jenkins pipeline automatically runs the `ansible/deploy.yml` playbook on the target server. Ansible pulls the latest image and starts the container bound to port `8081`. 
The result? Anyone can pull up the interactive C++ calculator simply by navigating their web browser to `http://<server-ip>:8081`.

## Using the Live Web App locally
To spin up the web-accessible version of the calculator locally (exactly how Ansible does it in production), use Docker:

```bash
# Pull the pre-configured Gotty image build
docker pull shreyasg28/sci-calc:latest

# Run it on host port 8081
docker run -d -p 8081:8081 --name my-calc shreyasg28/sci-calc:latest
```
Then simply open Firefox or Chrome and go to `http://localhost:8081`.
