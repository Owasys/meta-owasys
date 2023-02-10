# OWASYS YOCTO BSP

## SET-UP REPO
Owasys has developed its yocto layer from the yocto kirkstone distribution provided by NXP.

In order to use Yocto in any PC some dependencies must be installed. You can find them in [this](https://www.nxp.com/docs/en/user-guide/IMX_YOCTO_PROJECT_USERS_GUIDE.pdf) document provided by NXP in chapter 3. Once everything's installed you can follow on with the steps below.

To setup a building yocto environment for the owa5X family: 

1. Setup imx-nxp repo: 

~~~sh 
        $mkdir ~/bin
        $curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
        $chmod a+x ~/bin/repo
        $PATH=${PATH}:~/bin
        $mkdir owasys-yocto
        $cd owasys-yocto
        $repo init -u https://github.com/nxp-imx/imx-manifest -b imx-linux-kirkstone -m imx-5.15.32-2.0.0.xml
        $repo sync
~~~~

2. Enter the "owasys-yocto/sources" folder.
3. Clone the owasys layer in it:

        git clone https://github.com/Owasys/meta-owasys

4. Copy "meta-owasys/conf/owasys-setup.sh" to the root of the repo ( "../" ).

## BUILD

 1. source owasys-setup.sh -b build_owa5x
 2. bitbake cetus-image-nand

  ## FLASHING

 The end product of a successful building is a couple of files: 

 1. **owa5x-flash.bin**: contains the bootloader and several pieces of firmware that will run on the very first stages of the boot.
 2. **cetus-image-nand-owa5x.ubi**: rootfs for a NAND flash with the kernel and dtb embedded in it.
 
This files will be written by the flashing script **owa_uboot_nand_rootfs_YOCTO_2.0.0.uuu** to the corresponding memory onboard the owa5X. 
In order to do so: 

1. Copy the aforementioned script to the folder *build_owa5x/tmp/deploy/images/owa5x*, where after a succesfull image building artifacts are stored. 
2. Erase the u-boot partition: $u-boot-> nand erase.part NAND.u-boot
3. Turn owa5X off.
4. Connect owa5X to the PC through USB-to-USB cable.
5. Open up a console or terminal at your PC in the folder where the artifacts and scripts are.
6. Execute "sudo ~/uuu owa_uboot_nand_rootfs_YOCTO_2.0.0.uuu" 
7. Turn on the owa5X and the flashing process should start. 

### Problems?
1. ERROR: No space left on device or exceeds fs.inotify.max_user_watches?
    sudo sysctl -n -w fs.inotify.max_user_watches=512000
    
2. Previous error persists?
    echo fs.inotify.max_user_watches=512000 | sudo tee -a /etc/sysctl.conf

2. /usr/bin/env: ‘python’: No such file or directory
    1. sudo apt install python3
    2. sudo ln -s /usr/bin/python3.8 /usr/bin/python
