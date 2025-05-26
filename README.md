# 🚀 Long Message Module  

🔹 **Модуль расширяет стандартные функции сообщений в SA-MP**  
🔹 *Автор: [jrius](https://github.com/jr1us) | [VK](https://vk.com/s.fridom) | [Telegram](https://t.me/dcapybarov)*  
🔹 *Обзор*: [Youtube](https://www.youtube.com/watch?v=DZDpS_j7LcI) 

---

## 📌 Описание  
Модуль расширяет стандартные функции `SendClientMessage` и `SendClientMessageToAll`, позволяя отправлять сообщения длиннее **144 символов**, автоматически разбивая их на части.  

### 🔥 Особенности:  
✔ Поддержка **переносов строк** (`\n`)  
✔ Поддержка **табуляции** (`\t` → 4 пробела)    
✔ **Перехват хуками** – можно использовать стандартные вызовы  

---

## 📋 Функции  

### `SendClientMessage_Long(playerid, color, const input[])`  
Отправляет игроку длинное сообщение, разбивая его при необходимости.  

### `SendClientMessageToAll_Long(color, const input[])`  
Отправляет длинное сообщение **всем игрокам** на сервере.  

---

## ⚙ Установка  
1. Подключите модуль в начале мода:  
   ```pawn
   #include <long-message>
