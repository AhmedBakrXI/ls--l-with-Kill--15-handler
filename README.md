# ls--l-with-Kill--15-handler
To run this app

First, compile the files, then run the app with directories as arguments

Example
Input:
```bash
$ ./app . .. aa
```
Output:
```bash
.:
drwxr-xr-x 1 ahmed ahmed 4096 07 Aug 22:19 .vscode
drwxr-xr-x 1 ahmed ahmed 4096 07 Aug 22:14 aa
-rwxr-xr-x 1 ahmed ahmed 17048 08 Aug 00:08 app
-rw-r--r-- 1 ahmed ahmed 570 08 Aug 00:13 list.c
-rw-r--r-- 1 ahmed ahmed 3672 07 Aug 23:53 list_utils.c
-rw-r--r-- 1 ahmed ahmed 652 07 Aug 23:45 list_utils.h
-rw-r--r-- 1 ahmed ahmed 35 07 Aug 22:17 MakeFile

..:
-rw-r--r-- 1 ahmed ahmed 3771 28 Jul 11:59 .bashrc
-rw------- 1 ahmed ahmed 12705 08 Aug 00:31 .bash_history
-rw-r--r-- 1 ahmed ahmed 220 28 Jul 11:59 .bash_logout
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 12:19 .cache
drwxr-xr-x 1 ahmed ahmed 4096 03 Aug 16:51 .config
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 12:18 .dotnet
-rw------- 1 ahmed ahmed 20 07 Aug 19:53 .lesshst
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 12:40 .local
-rw-r--r-- 1 ahmed ahmed 0 08 Aug 00:32 .motd_shown
-rw-r--r-- 1 ahmed ahmed 807 28 Jul 11:59 .profile
-rw-r--r-- 1 ahmed ahmed 0 28 Jul 12:11 .sudo_as_admin_successful
-rw------- 1 ahmed ahmed 582 03 Aug 15:50 .viminfo
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 12:16 .vscode-remote-containers
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 12:16 .vscode-server
drwxr-xr-x 1 ahmed ahmed 4096 03 Aug 17:06 assignment
drwxr-xr-x 1 ahmed ahmed 4096 02 Aug 22:24 javaTest
drwxr-xr-x 1 ahmed ahmed 4096 08 Aug 00:08 ls_dash_l
drwxr-xr-x 1 ahmed ahmed 4096 03 Aug 10:55 siemens
drwxr-xr-x 1 ahmed ahmed 4096 28 Jul 13:01 ubuntu_siemens

aa:
-rw-r--r-- 1 ahmed ahmed 0 07 Aug 22:14 aa.s
```

As you can see, we can pass more than one directory at a time, but what happens if we didn't pass any arguments?

It will list the current directory
```bash
$ ./app
drwxr-xr-x 1 ahmed ahmed 4096 07 Aug 22:19 .vscode
drwxr-xr-x 1 ahmed ahmed 4096 07 Aug 22:14 aa
-rwxr-xr-x 1 ahmed ahmed 17048 08 Aug 00:08 app
-rw-r--r-- 1 ahmed ahmed 570 08 Aug 00:13 list.c
-rw-r--r-- 1 ahmed ahmed 3672 07 Aug 23:53 list_utils.c
-rw-r--r-- 1 ahmed ahmed 652 07 Aug 23:45 list_utils.h
-rw-r--r-- 1 ahmed ahmed 35 07 Aug 22:17 MakeFile
```


If you passed a wrong path then it will print no such file or directory
```bash
$ ./app asdas
opendir: No such file or directory
```

If you tried to terminate the process using SIGTERM (Signal 15), it will print "بس ياض"
![image](https://github.com/user-attachments/assets/d4b9df8b-32e8-48e0-bced-adcbb1114d73)
![image](https://github.com/user-attachments/assets/76b8b71d-084d-4f1a-867a-a246e87a8717)

If we failed to set the signal handle then it will print "Hahahaha"

ه
