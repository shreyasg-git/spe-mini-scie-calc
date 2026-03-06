// pipeline {
//     agent any

//     stages {

//         stage('Checkout') {
//             steps {
//                 git 'https://github.com/shreyasg-git/spe-mini-scie-calc'
//             }
//         }

//         stage('Build') {
//             steps {
//                 sh '''
//                 mkdir -p build
//                 cd build
//                 cmake ..
//                 make
//                 '''
//             }
//         }

//         stage('Run Binary') {
//             steps {
//                 sh '''
//                 ./build/calculator
//                 '''
//             }
//         }

//     }
// }