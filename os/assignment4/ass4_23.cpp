#include "myfs.h"
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <time.h>

const int MAXINODES  = 10;
const int MAXDISKBLOCKS  = 100;
char *mem = NULL;
struct stat st;

using namespace std;


struct superblock{
	int total_size;
	int max_inodes = MAXINODES;
	int actual_inodes;
	int max_diskblocks = MAXDISKBLOCKS;
	int actual_diskblocks_used;
	bitset<MAXDISKBLOCKS> diskblock_map;
	bitset<MAXINODES> inodes_map;
};

struct inodes{
	int file_type;	//0 denotes file, 1 denotes directory
	int file_size; 
	int time_last_read;
	bool permission_user;
	bool permission_writer; // not sure
	bool permission_other;
	int ptr[10];
};
/*
struct data_unit{
	char file_name[30];
	short int inode_number;
};*/

struct data_block{
	char data[256];
};

struct superblock *s;
struct inodes *i;
struct data_block *d;


int create_myfs(int size){
	*mem = new char[size];
	memset( mem, '\0', sizeof(mem) );

	s = (superblock *)mem;
	int sz = (sizeof(struct superblock) + size - 1)/size;
	i = (inodes *)(mem + sz);
	d = (data_block *)(mem + sz + MAXINODES);

	//initialization superblock
	s->total_size = size;
	s->max_inodes = MAXINODES;
	s->max_diskblocks = MAXDISKBLOCKS;
	s->actual_inodes = 1;
	s->actual_diskblocks_used = 1;
	s->inodes_map[0] = 1;

	//initialization inodes
	i->file_type = 1;
	i->file_size = 0;
	i->time_last_read = 0;
	i->permission_user = true;
	i->permission_other = true;
	i->permission_writer = true;
	memset(i->ptr, -1, sizeof(i->ptr));

	return 1;
}

int copy_pc2myfs (char *source, char *dest){
	s->actual_inodes++;

    stat(source, &st);
	(i + s->actual_inodes - 1)->file_type = 0;
	(i + s->actual_inodes - 1)->file_size = st.st_size;
	(i + s->actual_inodes - 1)->time_last_read = time(0);
	(i + s->actual_inodes - 1)->permission_writer = 
	(i + s->actual_inodes - 1)->permission_other  = 
	(i + s->actual_inodes - 1)->permission_other  = true;

	int fd = open(source, O_RDONLY);
	int n = 1;
	int count = 0;
	while(1){
		n = read(fd, (d + s->actual_diskblocks_used), 256);
        if (n == 0)
            break;
        if (n == -1) 
            cout << "error reading file" << endl;
        if(count < 8)
        	(i + s->actual_inodes - 1)->ptr[count++] = s->actual_diskblocks_used;
        else if(count < 18)

        else 
        	
        s->actual_diskblocks_used++;
	}

}

int rm_myfs (char *filename){

}

int ls_myfs (){

}

int main(){
	time(NULL);
	int mem = create_myfs(10000000);
	char *dest;
	char *source;
	if(mem == -1){ cout << "memory allocation failed" << endl; return 0; }
	for(int i = 0; i < 12; i++){
		source = "file"+i+".txt";
		dest = "file"+i+".txt";
		int copy_pc2myfs (source, dest);
	}
	int ls_myfs ();
	int rm_myfs (char *filename);
	int ls_myfs ();
}