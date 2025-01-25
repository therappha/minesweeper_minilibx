# 🕵️ Minesweeper (42 MiniLibX)

This is a **Minesweeper** game built using the **MiniLibX** library from **42 School**.\
The project is an adaptation of my previous terminal_minesweeper, but now I adapted it as a graphical game as a learning experience with MiniLibX and currently works **only on Linux**.\
When you win or lose it only shows a message in terminal and does nothing, you need to manualy close!

---

### 📥 Clone the Repository

```sh
git clone --recursive https://github.com/therappha/minesweeper_minilibx.git
```

### 🛠️ Build the Project

```sh
make
```

### 🎮 Run the Game

```sh
./game <board width> <board height> <number of bombs>
```

#### Example:

```sh
./game 10 10 10
```

This command will start a **10x10** board with **10 bombs**.

---

## 🏗️ Dependencies

- **Linux OS** (currently required)
- **MiniLibX** (included as a submodule)
- **Make & GCC** for compilation

---

## ⚠️ Notes

- Only tested on **Linux**.
- Ensure you have **MiniLibX** dependencies installed.

---

