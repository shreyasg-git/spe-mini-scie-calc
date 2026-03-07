pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                git 'https://github.com/shreyasg-git/spe-mini-scie-calc.git'
            }
        }

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