Project 2 Read Me

Class:        Computer Security
Group:        Group 3
Memebers:     Chris
              Sameep
              Aris
              Rebika
Description:  The goal of project two is to manage passwords hashed useing MD5 crypt.  
              We will implement an MD5 crypt to hash passwords, then compare password 
              attempts to existing hashed passwords file, and finally preform a rainbow
              table attack.
Implementation
       Password Hashing:
              - Up to 48 bit 
              - 128-bit hash
              - 1000 cycle slow down
       Password verification:
              - Take a password as input
              - Convert password to hash with salt value
              - Compare the hashes
       Rainbow Attack
              - Create rainbow file from a dictionary of words then calculate the hashes 
                with salt values from user ids
              - Use password verification with input from the rainbow file as input for 
                a password
