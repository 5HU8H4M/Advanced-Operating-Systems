- Our system is operating on ubuntu 18.04 (64 bit) system with 8 cores & kernel version 4.15

					uname -r  // shows 4.15

- We downloaded a kernel of higher version (4.17.4), this way the kernel gets automatically updated when you reboot the system after compiling.

	wget  https://www.kernel.org/pub/linux/kernel/v4.x/linux-4.17.4.tar.xz

- We extracted the kernel source code

			sudo tar -xvf linux-4.17.4.tar.xz -C/usr/src/

- Changed directory to where the files are extracted 

					cd /usr/src/linux-4.17.4/

- Then we defined a new system call sys_hello, inside a new directory
mkdir new_directory
cd new_directory

- Created a file ‘new_sys_call.c’
			            vim new_sys_call.c
- With source code as... 


(check new_sys-call.c)

( Press esc and then wq to save and quit the editor)

- Create a “Makefile” in the hello directory:
					gedit Makefile
  and add the following line to it:
				obj-y := new_sys_call.o  //This is to ensure that the hello.c file is compiled and included in the kernel source code.


- Adding hello directory to kernel’s makefile to tell the compiler that the source files of our new system call (sys_hello()) are present in the hello directory.
					 cd ../  // changing directory               
					gedit Makefile          
          
- Search for core-y in the document, you’ll find this line as the second instance of your search. Adding hello directory to this
		core-y += kernel/ mm/ fs/ ipc/ security/ crypto/ block/ hello/   

- Now we need to add our system call to our system call table
 	From linux-4.17.4/ directory:

					cd arch/x86/entry/syscalls/                                                            
					gedit syscall_64.tbl                                                                       


- Now we need to add this system call to the system call header file. From linux-4.17.4/ directory
				cd include/linux/											
        vim syscalls.h

Now we need to add the function prototype of our system call (last lline, add this)
				asmlinkage long sys_hello(void);


- Installing dependencies
				sudo apt-get install gcc
        sudo apt-get install libncurses5-dev
        sudo apt-get install bison
        sudo apt-get install flex
        sudo apt-get install libssl-dev
        sudo apt-get install libelf-dev
        sudo apt-get update
        sudo apt-get upgrade
        

- Now we’ll access the kernel and configure the kernel
  (selecting extended 4 file system)
				sudo make menuconfig

- Kernel compilation
				sudo make -j8 // for 8 cores

- Installing or updating kernel

				sudo make modules_install install

It will create some files under  /boot/  directory and it will automatically make a entry in your grub.cfg.

Checking /boot/ directory for these additional packages
      System.map-4.17.4
      vmlinuz-4.17.4
      initrd.img-4.17.4
      config-4.17.4						 

CONFIG FILE EDITS ( if error in make)
        scripts/config –set-str SYSTEM_TRUSTED_KEYS “”
        CONFIG_SYSTEM_REVOCATION_KEYS=”debian/canonical-revoked-certs.pem”
        scripts/config –disable SYSTEM_REVOCATION_KEYS
	
- Changing grub to new recompiled kernel
  Go back to the first directory using cd ../ repeatedly
  Go to grub config file
        
        cd etc/ default
        vim grub
        
  comment the line GRUB_TIMEOUT_STYLE = hidden      

Now to update the kernel in your system reboot the system
				shutdown -r now

on reboot, select the newly compiled kernel version 4.17

- After rebooting you can verify the kernel version
				uname -r
 

- Testing system call
				cd ~
				vim new_func_call.c

- Now, compile and run the program:
						gcc new_func_call.c
						./a.out
 
This will display our functional call, which in turn performs the system call and returns successfully.
In case if you want to display the internal system call message

						dmesg





        
        

