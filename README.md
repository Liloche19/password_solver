# password_solver - C

## A program that bruteforce the password of a user on linux

The program try all printable caracters in a string which grow each time the program finsihed all the combinations in a size of string.

## 🛠️ Installation

### Make sure to have the necessary dependencies :

**On Ubuntu / Debian :**

```bash
sudo apt install make gcc
```

**On Archlinux :**

```bash
sudo pacman -S install make gcc
```

### This is how to install the project :

Clone the repository :

```bash
git clone https://github.com/Liloche19/password_solver.git
cd password_solver
```

Then, compile the project :

```bash
make
```

**(OPTIONAL) :**

After use, you can remove all binary files (object), by running the following command :

```bash
make clean
```

You can also remove the executable file by running the following command :

```bash
make fclean
```

## This is how to launch the project :

```bash
./password_solver user
```

The outpout will look like this :

```bash
PASSWORD : [password] # Without the square brackets
```

## Contribution

If you have any proposition, you can contact me. I will be happy to improve this projet.
