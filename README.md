<h1>Advanced Password Manager</h1>
<h3>Overview</h3>
Welcome to the Advanced Password Manager! This application is designed to securely manage your passwords using custom-coded RSA encryption and Fast Positive Hash algorithms. The application is built using Qt and C++ to provide a powerful and user-friendly interface.

Please note: This project is intended for educational purposes and personal use only. It is not designed for production environments or storing sensitive data in real-world scenarios.

<h3>Features</h3>
Secure Password Storage: All passwords are encrypted using RSA encryption for maximum security.
Fast Positive Hash Algorithm: Ensures data integrity and quick password verification.
User-Friendly Interface: Built with Qt, the application offers an intuitive and easy-to-use interface.
Cross-Platform Support: Runs on multiple operating systems including Windows, macOS, and Linux.
Customizable Settings: Allows users to configure various settings to meet their specific needs.
<h3>Prerequisites</h3>
Qt Framework: Ensure that Qt is installed on your system. You can download it from Qt's official website.
C++ Compiler: A compatible C++ compiler is required to build the application. Popular choices include GCC (for Linux) and MSVC (for Windows).
<h3>Installation</h3>
Clone the Repository:
```
git clone https://github.com/yourusername/advanced-password-manager.git
cd advanced-password-manager
```
Build the Application:
```
mkdir build
cd build
qmake ../src
make
```
Run the Application:

```
./password-manager
```

<h3>Encryption and Hashing</h3>
<h4>RSA Encryption</h4>
The application uses custom-coded RSA encryption to ensure that all stored passwords are highly secure. This encryption is based on public-key cryptography, providing robust protection against unauthorized access. Only encrypted data is stored, ensuring that your passwords remain confidential.

<h4>Fast Positive Hash</h4>
To ensure data integrity and quick verification, the application uses a custom Fast Positive Hash algorithm. This hashing method is optimized for speed and security, ensuring that your data remains intact and consistent. Only hashed data is stored, providing an additional layer of security.
