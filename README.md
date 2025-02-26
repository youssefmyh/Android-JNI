# Android-JNI

This project demonstrates how to invoke C++ functions from Android's `MainActivity` using Java Native Interface (JNI) and receive callbacks utilizing the Observer design pattern.

## Features

- **JNI Integration**: Facilitates seamless communication between Java and C++ layers in an Android application.
- **Observer Pattern**: Implements a callback mechanism to notify Java code of events occurring in the native C++ layer.

## Prerequisites

- Android Studio with NDK support
- Basic knowledge of Java and C++

## Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/youssefmyh/Android-JNI.git
   ```
   This command will download the project files to your local machine.

2. **Open the Project in Android Studio**:
   - Launch Android Studio.
   - Select "Open an existing project" and navigate to the cloned repository's directory.

3. **Build the Project**:
   - Ensure the Android NDK is installed and configured in your Android Studio setup.
   - Click on "Build" > "Make Project" to compile the project.

4. **Run the Application**:
   - Connect an Android device or start an emulator.
   - Click on "Run" > "Run 'app'" to install and launch the application.

## Project Structure

- `app/src/main/java/com/example/androidjni/`: Contains Java source code, including `MainActivity` which interacts with the native layer.
- `app/src/main/cpp/`: Holds C++ source code and native method implementations.
- `app/src/main/cpp/CMakeLists.txt`: Build script for compiling the native code.

## How It Works

- **Java to C++**: `MainActivity` declares native methods and loads the native library. When these methods are called, control is passed to the corresponding C++ functions.
- **C++ to Java (Callback)**: The C++ layer maintains references to Java callback interfaces. Upon certain events, the C++ code invokes these callbacks, effectively notifying the Java layer of the event.

## Contributing

Contributions are welcome! Feel free to fork this repository, make enhancements, and submit pull requests.

## License

This project is licensed under the MIT License.

## Acknowledgments

- [Android NDK](https://developer.android.com/ndk) for enabling native code integration in Android apps.
- [JNI Documentation](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/) for providing insights into Java and native code interoperability.

For more information, visit the [GitHub repository](https://github.com/youssefmyh/Android-JNI). 
