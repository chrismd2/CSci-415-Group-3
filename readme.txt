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
              - Take salt as input
              - Up to 48 bit 
              - 128-bit hash
              - 1000 cycle slow down
              - Return hash
       Password verification:
              - Take a hash as input
              - The user end should compute the hash
              - Compare the hash to the password file
              - Return true if hash code is correct
       Rainbow Attack
              - Take the dictionary file as input
              - Create rainbow file which contains the hash values computed from all 
                combinations of dictionary words and salt values
              - Use password verification with input from the rainbow file as input for 
                a password
