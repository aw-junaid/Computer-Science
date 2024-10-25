Exporting a file system with NFS in Linux involves making a directory available to be mounted and accessed by other Linux systems on the network. The system exporting the directory is called the NFS server, and the systems mounting the directory are called NFS clients. Here's a step-by-step guide to exporting a file system with NFS in Linux:

1. Install NFS:

Ensure NFS is installed on the NFS server. The installation process may vary depending on your Linux distribution.

On Ubuntu/Debian (NFS server):
```bash
sudo apt-get install nfs-kernel-server
```

On CentOS/RHEL (NFS server):
```bash
sudo yum install nfs-utils
```

2. Choose a Directory to Export:

Choose a directory on the NFS server that you want to share with NFS clients. For example, let's use `/mnt/shared` as the directory to export.

3. Configure the NFS Exports File:

Open the NFS exports file for editing:
```bash
sudo nano /etc/exports
```

Add a line to the file to specify the directory to be exported and the NFS client(s) allowed to mount it. The general syntax is:
```
/exported_directory client_IP(options)
```
For example, to allow access to the `/mnt/shared` directory from a specific NFS client with IP address `192.168.1.100`, add the following line:
```
/mnt/shared 192.168.1.100(rw,sync,no_subtree_check)
```
Replace `/mnt/shared` with the path to your chosen directory and `192.168.1.100` with the IP address of the NFS client you want to grant access to. The `(rw,sync,no_subtree_check)` options allow the client to read and write to the exported directory.

If you want to allow access from multiple clients, add additional lines with different IP addresses and options.

4. Save and Close the File:

Save the changes and close the editor.

5. Apply the NFS Configuration:

Apply the changes to the NFS exports by running:
```bash
sudo exportfs -a
```

6. Start and Enable NFS Services:

Start and enable the NFS server service to make sure it starts automatically on boot:
```bash
sudo systemctl start nfs-server
sudo systemctl enable nfs-server
```

7. Allow NFS Traffic Through the Firewall (Optional):

If you have a firewall enabled on the NFS server, you need to allow NFS traffic. The specific commands may vary depending on your firewall software (e.g., iptables or firewalld).

For example, with `iptables`, you can allow NFS traffic using the following commands:
```bash
sudo iptables -A INPUT -p tcp --dport 2049 -j ACCEPT
sudo iptables -A INPUT -p udp --dport 2049 -j ACCEPT
sudo iptables-save | sudo tee /etc/iptables/rules.v4
```

8. Configure the NFS Client (on the remote machine):

On the NFS client machine, create a directory where you want to mount the NFS share:
```bash
sudo mkdir /mnt/nfs
```

Mount the NFS share from the server to the client:
```bash
sudo mount nfs_server_ip:/mnt/shared /mnt/nfs
```
Replace `nfs_server_ip` with the IP address or hostname of the NFS server.

9. Test the NFS Share:

You should now be able to access the shared files from the NFS server on the NFS client at the mount point `/mnt/nfs`.

10. Automount the NFS Share (Optional):

To automatically mount the NFS share on the client at boot time, you can add an entry to the `/etc/fstab` file on the client:
```bash
sudo nano /etc/fstab
```

Add the following line to the file:
```
nfs_server_ip:/mnt/shared /mnt/nfs nfs defaults 0 0
```
Replace `nfs_server_ip` with the IP address or hostname of the NFS server.

Save and close the file.

11. Test the Automount (Optional):

Reboot the NFS client, and the NFS share should be automatically mounted at the specified mount point.

Conclusion:

By following these steps, you can export a file system with NFS in Linux and make it accessible to NFS clients over the network. NFS provides a straightforward and efficient way to share directories and files between Linux systems, making it a popular choice for networked file sharing in Linux environments.
