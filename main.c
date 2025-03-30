 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void toggleLight(int rooms, int lights[]);
 void readTemperature(int rooms, int temp[]);
 void checkMotionSensor(int rooms, int motion[]);
 void lockUnlockSecurity(int rooms, int locks[]);
 void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void autoLockCheck(int rooms, int motion[], int locks[], int *idleCount);
 void temperatureAlert(int rooms, int temp[]);
 
 int main() {
     int rooms, choice, idleCount = 0;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
     
     int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
     initializeSystem(rooms, lights, temp, motion, locks);
     
     do{
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status\n6. Exit\nEnter choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1: toggleLight(rooms, lights); break;
             case 2: readTemperature(rooms, temp); break;
             case 3: checkMotionSensor(rooms, motion); idleCount++; break;
             case 4: lockUnlockSecurity(rooms, locks); break;
             case 5: houseStatus(rooms, lights, temp, motion, locks); break;
             case 6: return 0;
             default: printf("Invalid choice. Try again.\n");
         }
         autoLockCheck(rooms, motion, locks, &idleCount);
         temperatureAlert(rooms, temp);
     }while (choice!=6);    
 }
 
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0; temp[i] = 22 + (rand() % 10); motion[i] = 0; locks[i] = 1;
     }
     printf("System Initialized.\n");
 }
 
 void toggleLight(int rooms, int lights[]) {
     int room; printf("Enter room number (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         lights[room - 1] = !lights[room - 1];
         printf("Room %d Light %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     }
 }
 
 void readTemperature(int rooms, int temp[]) {
     int room; printf("Enter room number (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Room %d Temp: %d°C\n", room, temp[room - 1]);
     }
 }
 
 void checkMotionSensor(int rooms, int motion[]) {
     int room; printf("Enter room number (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Room %d Motion: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
     }
 }
 
 void lockUnlockSecurity(int rooms, int locks[]) {
     int room; printf("Enter room number (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         locks[room - 1] = !locks[room - 1];
         printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
     }
 }
 
 void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1, lights[i] ? "ON" : "OFF", temp[i], motion[i] ? "Motion Detected" : "No Motion", locks[i] ? "Locked" : "Unlocked");
     }
 }
 
 void autoLockCheck(int rooms, int motion[], int locks[], int *idleCount) {
     if (*idleCount >= 5) {
         for (int i = 0; i < rooms; i++) {
             if (motion[i] == 0) locks[i] = 1;
         }
         printf("Auto-Lock Activated: Unused rooms locked.\n");
         *idleCount = 0;
     }
 }
 
 void temperatureAlert(int rooms, int temp[]) {
     for (int i = 0; i < rooms; i++) {
         if (temp[i] > 30) printf("Warning: Room %d temperature above 30°C!\n", i + 1);
     }
 }
 

