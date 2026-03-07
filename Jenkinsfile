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

        stage('Deploy (Ansible)') {
            steps {
                // Using connection=local assumes Jenkins has ansible installed and Docker access
                sh 'ansible-playbook -i ansible/inventory.ini ansible/deploy.yml --connection=local'
            }
        }

    }

    post {
        always {
            mail to: 'shreyasbgangurde@gmail.com',
                 subject: "Jenkins Pipeline Status: ${currentBuild.fullDisplayName}",
                 body: "The pipeline ${env.JOB_NAME} build ${env.BUILD_NUMBER} finished with status: ${currentBuild.currentResult}.\nCheck console output at: ${env.BUILD_URL}"
        }
    }
}