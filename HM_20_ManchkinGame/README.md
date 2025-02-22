# Munchkin Game Development

## Completed task

### a. Extend UI to Output Monster Information
- **[Done]** Extended UI for RunAwayPolicy `std::string RunawayPolicy::getFullInfo()`
![image](https://github.com/user-attachments/assets/8e8d159c-1e6a-4e6b-809a-b6ea309f678d)
![image](https://github.com/user-attachments/assets/da418c72-c6de-41d7-8acb-6fbec6f10692)

### b. New Items with Special Parameters
- 🟩 Added **Holy Sword** that destroys **Zombie** instantly
- 🟩 Implemented class `HollyWeapon`
- 🟩 Implemented class `BrutalWeapon`

### c. Unique Generation Methods for Items, Modifiers, and Monsters
- 🟩 Created `MonsterDeck::generateMonster()`
- 🟩 Created `ModifierDeck::generateModifier()`
- 🟩 Created `ItemDeck::generateItems()`
- 🟩 Ensured that each "item" (modifier, item, or monster) appears only **once** per deck cycle
  ![image](https://github.com/user-attachments/assets/f85221a0-efc6-4bfe-a472-404c77cf0b28)
- Amout of outfit and hand cards can be changed in a private members of: 
    * class ModifierDeck->m_modifiersAmount
    * class ItemsDeck->m_itemsAmount
- 🟩 Added destructors for Clases: modifier, item, monster.
  
### e. Runaway Policies Implementation
- 🟩 `Runaway_ItemEquipedRemoval`
- 🟩 `Runaway_ModifierFromHandRemoval`
- 🟩 `Runaway_BiggestBonusCardRemoval`

### f. New Modifier Types
- 🟩 `HalvesMonsterLevel`
- 🟩 `RaceModifier`
  - Added 3 races for players: **Ork**, **Elph**, **Human**
  - ![image](https://github.com/user-attachments/assets/a174afa4-c501-437d-b9b1-2cb2260b1693)
  - Players can choose a race at the start of the game


