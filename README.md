 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Iaredell
 
 > Authors: [Nicole Carter (ncart018)](https://github.com/nicolec702) 
 > [Fadak Abdullah (@fabdu013)](https://github.com/faduckie)
[Steven Truong (@struo025)](https://github.com/Steven-Eon)
[Victor Sandoval (@vsand012)](https://github.com/VMSandoval25)


## Project Description
> **Project Importance:**
> - We found the Text-Based RPG game to be the most creatively liberating out of the list of projects. We still had a guideline of what we needed to do, but we also have  infinite possibilities to expand on the project.

> Language: C++
> 
> **Features:**
> - A Storyline.
> - Dialogue System.
>   - Plan on using dialogue tree
> - XP Scaling System
>   - Later quests/enemies give you more xp
>   - They also deal more damage/have more health
> - Four distinct characters the player can choose from
>   - Four different classes + weapons 
> - Healing items (can sometimes randomly appear)
> - Leveling System
>   - Gain xp through:
>     - Killing enemies
>     - Completing quests
>   - Every time you level up your health/damage dealt is increased


## Class Diagram
 > ![UML Diagram](ProjectUML.png)
 >The Character class will have two subclasses, InformationCharacter and AttackCharacter. The InformationCharacter will initiate an object of type Quests and there will be an aggregation link between both classes. The Quest class will read text from a file that will be used to narrate the storyline of our game. The AttackCharacter class will have an object of type Attribute and this will create an aggregation link between the AttackCharacter and Attribute class. This means that they can both exist independently of each other. The purpose of the attribute class is to keep track of the AttackCharacter’s hp, defense level, attack level, and stamina level. This is done in an effort to maintain modularity and keep the classes clean. AttackCharacter will also initiate an object of type Weapons. There will be an aggregation link between both classes. The Weapons class will make use of the strategy WeaponBehavior. WeaponsBehavior will declare an interface that all supported algorithms will use. These algorithms include LongSword, Staff, Daggers, Broom, and Basic. WeaponBehavior has an aggregation link with the Weapons class.
 > ## Phase III
 > **Strategy Pattern**
 > * For our weapons class we decided to use the strategy pattern because we realized that the weapons the player characters will be using are all the same object with similar member variables, the only difference is how much damage each weapon deals. Instead of creating five different classes for each weapon, we could create one class that has five different ‘strategies’ that could be swapped out depending on which weapon the player character is using. These strategies refer to the weapon behavior so we have a long sword strategy, a staff strategy, a dagger strategy, etc. This helps with minimizing unnecessary and redundant code and allows us to add more weapon strategies if we need to without any problems.
 > **Abstract Factory Pattern**
 > * ...(will add)

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > * The project was tested by creating unit tests with the gtest submodule, and valgrind for memory leak checks.
