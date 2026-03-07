pipeline {
    agent any

    stages {

       

        stage('Build (CMake)') {
            steps {
                sh '''
                mkdir -p build
                cd build
                cmake ..
                make
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                sh '''
                cd build
                # Run all tests EXCEPT IntegrationTest
                ctest --output-on-failure -E "^IntegrationTest$"
                '''
            }
        }

        stage('Integration Tests') {
            steps {
                sh '''
                cd build
                # Run ONLY the IntegrationTest and set a generic terminal for ncurses
                export TERM=xterm-256color
                ctest --output-on-failure -R "^IntegrationTest$"
                '''
            }
        }

        stage('Build Docker Image') {
            steps {
                sh '''
                DOCKER_BUILDKIT=1 docker build -t shreyasg28/sci-calc .
                '''
            }
        }

        stage('Push Docker Image') {
            steps {
                sh '''
                docker push shreyasg28/sci-calc:latest
                '''
            }
        }

    }
}