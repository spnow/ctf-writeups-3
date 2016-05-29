## Ghost in the Shellcode 2014 - TrustMeMore (RE 150)
##### 17-19/01/2014 (36hr)
___

### Description: 

We let your ex write a service. Running at trustmemore.2014.ghostintheshellcode.com:7457. 
Password: trust is 74u57 -- but l33t doesn't have a u. Note: This challenge is not NAT-friendly.

___
### Solutcion

1.Execute program from tor
2.Send the rsa private key (2KB)
3.Then listen on port 22 with sshd service
4.Make port forwarding in order to allow remote access.
5.Server will connect to you and leave a file with name gits in local directory

___