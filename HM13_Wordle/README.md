

# Word Guessing Game

## What was implemented:

### 🎮 TWO Modes

1. ## Random Word
2. ## Word of the Day

---

## 🟢 Mode: [1] Random Word
![image](https://github.com/user-attachments/assets/97431c9d-750a-4766-a751-ed37d714f7dc)

Before the player inputs a word, the game opens the file "RandomWordDataBase.txt", which stores the words for this mode. The first element in the file is an `integer` that indicates the number of words in `.txt`.

The game then shuffles these words using a **dynamically allocated array type `std::string` in the heap**. After shuffling, the word at index `0` becomes the **target word** for the player.

### **📌 Input Rules**

- The player must enter a **5-letter word**.
- If the word is **shorter or longer**, the game asks to **re-enter** it.
- **Invalid attempts** (wrong length) are **not counted** in the attempt statistics.

### **🔎 Guess Checking Algorithm**

1. The game checks whether the letters in the player's input match the letters in the **target word** in the **correct positions** via:
```cpp
void correctPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used)
```
2. If a letter **matches and is in the correct position**, it is **marked as used**:
   ```cpp
   used[i] = true;
   ```
   where `i` is the index of the letter in the array.
3. The game then checks **each letter** in the input to see if it exists in the **target word**, regardless of its position via:
```cpp
void incorrectPos(std::string& playerInput, const std::string& mysteryWord, std::string& mysteryPlaceholder, bool* used)
```
4. If a **matching letter** is found, it is **also marked as **
   ```cpp
   used[i] = true;
   ```
5. Letters **not found** in the word remain \`\`\*\* (hidden)\*\*.

  ![image](https://github.com/user-attachments/assets/5ce9df8e-feb5-4117-868e-46d11a7dfa91)

6. The loop while **repeats until the player correctly guesses the word**.
   ```cpp
   mysteryWord != playerInput
   ```
8. After the correct guess, **the number of attempts is calculated**, with `+1` for each valid 5-letter input.

---

## 🟡 Mode: [2] Word of the Day

The input processing **works exactly the same** as in the `Random Word` mode. The main difference is **whether the player has already played today**.

### **📅 Checking if the player has played today**

This is handled using the function:

```cpp
bool IsWordGuessToday(const char* fileName, const int& day, const int& month, const int& year);
```

- This function **compares the current date** with the one stored in `CrossStart` via
  func from <ctime>
   ```cpp
   int getDay(const std::tm* tmObj);
   int getMonth(const std::tm* tmObj);
   int getYear(const std::tm* tmObj);
   ```
- By default, the file contains:
  ```
  0 
  0 
  0
  ```
  which means **no game has been played today**.
- If the date **differs from today**, the function returns `true` and the game **updates today's date in the file**.
  ```
  0 -> current_day
  0 -> current_month
  0 -> current_year
  ```
- If the date **matches today's date**, the game **displays a message** saying that today's word has already been guessed:
  ![image](https://github.com/user-attachments/assets/7f90125b-4c5d-4a86-89b0-bbe1dce4ab63)

### **📌 Word Selection Process**

- If the date check **passes**, the game **opens** the file `WordOfDay.txt`.
- Work similar to the `Random Word` mode:
  1. **Shuffles the words**.
  2. **Randomly selects one word** as the **target word**.
BUT Unlike the `Random Word` mode, in `WordOfDay`, the choosed word **is permanently removed** from the file to ensure that the same word is not selected again.

---

## **🔧 Known Issues in algorithm accordingly to the test cases**
![image](https://github.com/user-attachments/assets/2b249aa0-a9ac-46de-9eca-2ac76d57c575)
![image](https://github.com/user-attachments/assets/74519203-a673-4ac2-a2c2-75b45927a999)
