Sharing files with NFS (Network File System) in Linux allows you to access files and directories from one Linux system (NFS server) on another Linux system (NFS client) over the network. NFS provides a convenient way to share files and is commonly used in Linux environments. Here's a step-by-step guide on how to share files with NFS in Linux:

Note: For this guide, we assume you have two Linux systems, one acting as the NFS server and the other as the NFS client.

1. Install NFS:

Ensure that NFS is installed on both the NFS server and client. The installation process may vary depending on your Linux distribution.

On Ubuntu/Debian (NFS server and client):
```bash
sudo apt-get install nfs-kernel-server nfs-common
```

On CentOS/RHEL (NFS server and client):
```bash
sudo yum install nfs-utils
```

2. Configure the NFS Server:

a. Export the Directory:

Choose a directory on the NFS server that you want to share. For example, let's use `/mnt/shared` as the shared directory. Open the NFS exports file for editing:
```bash
sudo nano /etc/exports
```

Add the following line to the file to export the directory to the NFS client:
```
/mnt/shared   *(rw,sync,no_subtree_check)
```
Replace `/mnt/shared` with the path to your chosen shared directory.

b. Save and Close the File:

Save the changes and close the editor.

c. Apply the Configuration:

Apply the changes to the NFS exports by running:
```bash
sudo exportfs -a
```

3. Start and Enable NFS Services:

On the NFS server, start and enable the NFS server service to make sure it starts automatically on boot:
```bash
sudo systemctl start nfs-server
sudo systemctl enable nfs-server
```

4. Configure the NFS Client:

a. Create a Mount Point:

On the NFS client, create a mount point for the shared directory. For example:
```bash
sudo mkdir /mnt/shared
```

b. Mount the NFS Share:

Mount the shared directory from the NFS server to the client:
```bash
sudo mount nfs_server_ip:/mnt/shared /mnt/shared
```
Replace `nfs_server_ip` with the IP address or hostname of the NFS server.

5. Test the NFS Share:

You should now be able to access the shared files from the NFS server on the NFS client. To test, create a file on the NFS server in the shared directory and check if it appears in the same location on the NFS client.

6. Automount the NFS Share (Optional):

To automatically mount the NFS share on the client at boot time, you can add an entry to the `/etc/fstab` file:
```bash
sudo nano /etc/fstab
```

Add the following line to the file:
```
nfs_server_ip:/mnt/shared /mnt/shared nfs defaults 0 0
```
Replace `nfs_server_ip` with the IP address or hostname of the NFS server.

Save and close the file.

7. Test the Automount (Optional):

Reboot the NFS client, and the NFS share should be automatically mounted at the specified mount point.

Conclusion:

By following this guide, you can share files with NFS in Linux. The NFS server exports a directory, and the NFS client mounts that directory to access the shared files over the network. NFS provides a simple and efficient way to share files between Linux systems and is widely used in networked environments.
