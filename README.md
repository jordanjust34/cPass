# Preface

This project is not, at the moment, intended for serious usage. This is a personal project I developed in my free time for personal use and future development/implimentation. Thank you for reading this.

# CPass

A simple CLI-based password manager written in C++. It allows you to securely store, list, and retrieve passwords for different websites using a master password for encryption.

Currently not supported for Windows...

## Features

- **Secure Storage**: Encrypts website, username, and password using a master password.
- **Simple CLI Interface**: Easy to use commands for managing your credentials.
- **Zero Dependencies**: Uses bundled `nlohmann/json` for easy setup.

## Commands

Use the following flags to perform different actions:

| Flag | Alias | Description |
| :--- | :--- | :--- |
| `-n`, `--new` | `N` | Add a new password (Requires: website, username/email, password) |
| `-l`, `--list` | `L` | List all stored passwords |
| `-r`, `--remove`, `-rm` | `R` | Remove a password entry for a specific site |
| `-purge` | `PURGE` | Purge all stored data |
| (none) | (default) | Copies the decrypted password for a specific website to the users clipboard |

# Requirements

MacOS: `pbcopy`
Linux: `xclip`

# Roadmap

- Initial Release
- Stronger User Verification
- Stronger Password Encryption

---

### Examples

**Add a new password:**
```bash
./bin/cpass -n "google.com" "user@gmail.com" "mysecretpassword"
```

**Retrieve a password:**
```bash
./bin/cpass "google.com"
```

**List all passwords:**
```bash
./bin/cpass -l
```

**Remove a password entry:**
```bash
./bin/cpass -r "google.com"
```

## Building from Source

Ensure you have `g++` and a C++17 compatible compiler installed.

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd cPass
   ```

2. Build the project using `make`:
   ```bash
   make all
   ```

3. (Optional) Run tests:
   ```bash
   make test
   ```

4. (Optional) Create a debug build:
   ```bash
   make debug
   ```

## Cleaning up

To remove build artifacts:
```bash
make clean
```

To completely remove all generated files and binaries:
```bash
make distclean
```
