Install
=======

Quick Start
-----------

Normally, users can build pynvme by simply running *install.sh*. It generates the pynvme Python package *nvme.so*. This is the recommended method to compile pynvme.

.. code-block:: shell

   git clone https://github.com/pynvme/pynvme
   cd pynvme
   ./install.sh
   
Users then can import the package for NVMe test scripts:

.. code-block:: python

   import nvme as d
   nvme0 = d.Controller(b"01:00.0")  
   
We will describe more details of installation below, in case *install.sh* cannot give you the expected package binary file. 

System Requirements
-------------------

Pynvme is a software-defined NVMe test solution, so users can install and use pynvme in most of the commodity computers with some requirements:

#. CPU: Intel x86_64.
#. Memory: 4GB or larger.
#. OS: Linux. Fedora is recommanded. 
#. Python3: Python2 is not supported.
#. sudo privilege is required.
#. NVMe: NVMe SSD is the devices to be tested. Backup your data!
#. RAID mode (Intel® RST): should be disabled in BIOS.
#. Secure boot: should be disabled in BIOS.
#. IOMMU: (a.k.a. VT for Direct I/O) should be disabled in BIOS.
#. VMD: should be disabled in BIOS.
#. NUMA: recommend to be disabled in BIOS.
#. SATA: recommend to install OS and pynvme in a SATA drive.

   
Source Code
-----------

We clone the pynvme source code from GitHub. We recommend to checkout the latest stable release. 

.. code-block:: shell

   git clone https://github.com/pynvme/pynvme
   cd pynvme
   git checkout tags/1.7

   
Prerequisites
-------------

Then, we need to fetch all required dependencies. 

.. code-block:: shell

   # fedora-like
   sudo dnf install -y make redhat-rpm-config python3-devel python3-pip

   # ubuntu-like
   sudo apt install -y python3-setuptools python3-dev python3-pip 

   # get SPDK and its submodules
   git submodule update --init --recursive

   # install SPDK required packages
   sudo ./spdk/scripts/pkgdep.sh

   # install python packages required by pynvme
   sudo python3 -m pip install -r requirements.txt

   
SPDK
----

We need to compile and test SPDK first. 

.. code-block:: shell

   # use the according pynvme-modified SPDK code
   cd spdk
   git checkout pynvme_1.3

   # configure SPDK
   ./configure --without-isal;

   # compile SPDK
   cd ..   
   make spdk

   # compile pynvme
   make

Now, we can find a generated binary file like: *nvme.cpython-37m-x86_64-linux-gnu.so*.

Test
----
                
After compilation, let's first verify if SPDK works in your platform with SPDK applications. Before moving forward, check and backup your data in the NVMe SSD.

.. code-block:: shell

   # setup SPDK runtime environment             
   make setup

   # compile the application
   cd spdk/examples/nvme/identify
   sudo make

   # run the application
   sudo ./identify

This application lists identify data of your NVMe SSD. If it works, let's move ahead to run pynvme tests!

.. code-block:: shell

   cd ~/pynvme
   make setup
   make test TESTS="driver_test.py::test_ioworker_iops_multiple_queue[1]"

After the test, we can find the file *test.log* in pynvme directory, which keeps more debug logs than that in the standard output. When you meet any problem, please submit issues with this *test.log*. 

*make setup* allocates hugepages and reserves NVMe devices for SPDK runtime environment. When you want to release memory and NVMe devices back to kernel, execute this command:

.. code-block:: shell

   make reset

OK! Pynvme is ready now. 
