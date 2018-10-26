#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define INF 10000000000

struct pageTable{
	bitset<32> entry;
};



struct pageTable PageTable[64+1]; 
queue<int> FIFO_QUEUE;

void intitialise(){
	for(int i = 0; i < 65; i++)
		PageTable[i].entry = 0;
}

void printpagetable(){
	for(int i = 0; i < 65; i++){
		cout <<"Page : " <<  i << " " << PageTable[i].entry << endl; 
	}
}

void print(int MAX_FRAME){
	bitset<32> tmp;
	int frame;
	int flag;
	cout << "   FRAME TABLE    " << endl;
	for(int i = 1; i <= MAX_FRAME; i++){
		flag = 0;
		for(int j = 1; j < 65; j++){
			tmp = PageTable[j].entry;
			tmp >>= 3;
			frame = (int)tmp.to_ulong();
			if(frame == i){
				cout << "frame : " << i << "  " << j << endl;
				flag = 1;
			}
		}
		if(!flag) cout << "frame : " << i << "  " << -1 << endl;
	}
	cout << endl;
}

int FIFO_UTIL(){
	int frame = FIFO_QUEUE.front();
	FIFO_QUEUE.pop();

	return frame;
}
void FIFO(){
	int MAX_FRAME, CURR_FRAME = 1;
	cout << "Frame size" << endl;
	cin >> MAX_FRAME;
	int frame;
	int Write, Page;
	int virtualpage;
	int pagefault = 0, transfer = 0;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	long long int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page = 0;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inp",ios::in);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return ;
    }
    intitialise();
	while(!st.eof()){
			// cin >> Write >> Page;
			st >> Write >> Page;  // Step 4: Reading from file
			if(Write == 1)                         							
				PageTable[Page].entry[1] = 1;   							// if write,  modified bit = 1
			PageTable[Page].entry[2] = 1;       							// reference bit = 1
			cycle++; 
			if(PageTable[Page].entry[0]){
				cout << "Page Found " << endl;
			}
			else{
				cout << "Page Fault" << endl;
				pagefault++;
				if(CURR_FRAME <= MAX_FRAME){
					// Move page to CURR_FRAME
					PageTable[Page].entry[0] = 1;   // valid bit
					// set frame number in page in PageTable
					frmbit = CURR_FRAME;
					frmbit <<= 3;
					frmbit[0] = 1;
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
					cout << "IN" << Page << "  "<<CURR_FRAME << endl;
					transfer++;
					cout << "MAP" << Page << "  " << CURR_FRAME << endl;
					cycle+=3000+250;
					CURR_FRAME++;
				}
				else{
					page = FIFO_UTIL();
					temp = PageTable[page].entry;
					temp >>= 3;
					frame = (int)temp.to_ulong();

					cout << "UNMAP " << page << " " << frame << endl;
					if(PageTable[page].entry[1] == 1){
						cout << "OUT" << page << " " << frame << endl;
						cycle+=3000;
						transfer++;
					}
					cout << "IN  " << Page << " " << frame << endl;
					transfer++;
					cout << "MAP " << Page << " " << frame << endl;
					cycle+=250+3000+250;
					PageTable[page].entry = 0;  
					PageTable[Page].entry[0] = 1;				// valid bit set to 1
					// set frame number in page in PageTable
					frmbit = frame;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
				}

			}
			print(MAX_FRAME);
		}
	cout << endl;
	cout << "Cycles " << cycle << endl;
	cout << "Page Faults " << pagefault << endl;
	cout << "Page transfer " << transfer << endl;
	st.close(); // Step 5: Closing file

}
int RANDOM_UTIL(){
	int page;

	while(1){
		page = (rand() + 1) % 65;
		if(PageTable[page].entry[0])
			return page; 
	}

}

void RANDOM(){
	int MAX_FRAME, CURR_FRAME = 1;
	cout << "Frame size" << endl;
	cin >> MAX_FRAME;
	int frame;
	int Write, Page;
	int pagefault = 0, transfer = 0;
	int virtualpage;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	long long int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page = 0;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inp",ios::in);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return ;
    }
    intitialise();
	while(!st.eof()){
			// cin >> Write >> Page;
			st >> Write >> Page;  // Step 4: Reading from file
			//cout << Write << " " << Page << endl; 
			if(Write == 1)                         							
				PageTable[Page].entry[1] = 1;   							// if write,  modified bit = 1
			PageTable[Page].entry[2] = 1;       							// reference bit = 1
			cycle++; 
			if(PageTable[Page].entry[0]){
				cout << "Page Found " << endl;
			}
			else{
				cout << "Page Fault" << endl;
				pagefault++;
				if(CURR_FRAME <= MAX_FRAME){
					// Move page to CURR_FRAME
					PageTable[Page].entry[0] = 1;   // valid bit
					// set frame number in page in PageTable
					frmbit = CURR_FRAME;
					frmbit <<= 3;
					frmbit[0] = 1;
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
					cout << "IN" << Page << "  "<<CURR_FRAME << endl;
					transfer++;
					cout << "MAP" << Page << "  " << CURR_FRAME << endl;
					cycle+=3000+250;
					CURR_FRAME++;
				}
				else{
					page = RANDOM_UTIL();
					temp = PageTable[page].entry;
					temp >>= 3;
					frame = (int)temp.to_ulong();

					cout << "UNMAP " << page << " " << frame << endl;
					if(PageTable[page].entry[1] == 1){
						cout << "OUT" << page << " " << frame << endl;
						cycle+=3000;
						transfer++;
					}
					cout << "IN  " << Page << " " << frame << endl;
					transfer++;
					cout << "MAP " << Page << " " << frame << endl;
					cycle+=250+3000+250;
					PageTable[page].entry = 0;  
					PageTable[Page].entry[0] = 1;				// valid bit set to 1
					// set frame number in page in PageTable
					frmbit = frame;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
				}

			}
			print(MAX_FRAME);
		}	
	cout << "Cycles " << cycle << endl;
	cout << "Page Faults " << pagefault << endl;
	cout << "Page transfer " << transfer << endl;
	st.close(); // Step 5: Closing file

}

int SecondChance_UTIL(){
	int Page;
	while(1){
		Page = FIFO_QUEUE.front();
		if(PageTable[Page].entry[2] == 0){
			FIFO_QUEUE.pop();
			return Page;
		}
		else{
			PageTable[Page].entry[2] = 0;
			FIFO_QUEUE.pop();
			FIFO_QUEUE.push(Page);
		}
		//cout << Page << endl;
	}
}

void SecondChance(){
	int MAX_FRAME, CURR_FRAME = 1;
	cin >> MAX_FRAME;
	int frame;
	int Write, Page;
	int virtualpage;
	int pagefault = 0, transfer = 0;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	long long int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inp",ios::in);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return;
    }
    intitialise();
    while (!FIFO_QUEUE.empty())
    {
        //cout << '\t' << g.front();
        FIFO_QUEUE.pop();
    }
	while(!st.eof()){
			st >> Write >> Page;
			//cout << Write << Page << endl;
			if(Write == 1)                         							
				PageTable[Page].entry[1] = 1;   							// if write,  modified bit = 1
			PageTable[Page].entry[2] = 1;       							// reference bit = 1 
			if(PageTable[Page].entry[0]){
				cout << "Page Found " << endl;
			}
			else{
				cout << "Page Fault" << endl;
				pagefault++;
				if(CURR_FRAME <= MAX_FRAME){
					// Move page to CURR_FRAME
					FIFO_QUEUE.push(Page);
					PageTable[Page].entry[0] = 1;   // valid bit
					// set frame number in page in PageTable
					frmbit = CURR_FRAME;
					frmbit <<= 3;
					frmbit[0] = 1;
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					cout << "IN" << Page << "  "<<CURR_FRAME << endl;
					transfer++;
					cout << "MAP" << Page << "  " << CURR_FRAME << endl;
					cycle+=3000+250;
					CURR_FRAME++;
				}
				else{
					page = SecondChance_UTIL();
					temp = PageTable[page].entry;
					temp >>= 3;
					frame = (int)temp.to_ulong();

					cout << "UNMAP " << page << " " << frame << endl;
					if(PageTable[page].entry[1] == 1){
						cout << "OUT" << page << " " << frame << endl;
						cycle+=3000;
						transfer++;
					}
					cout << "IN  " << Page << " " << frame << endl;
					transfer++;
					cout << "MAP " << Page << " " << frame << endl;
					cycle+=250+3000+250;

					PageTable[Page].entry[0] = 1;   				// valid bit
					PageTable[page].entry = 0;                        		// bit set to 0
					// set frame number in page in PageTable
					frmbit = frame;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
				}

			}
			//cout << FIFO_QUEUE.front() << endl;
			print(MAX_FRAME);
		}
	cout << endl;
	cout << "Cycles " << cycle << endl;
	cout << "Page Faults " << pagefault << endl;
	cout << "Page transfer " << transfer << endl;

	st.close();

}

int LRU_UTIL(vector<long long int> leastrecent){
	int flag = 1;
	int i;
	for(i = 2; i < leastrecent.size(); i++)
		if(leastrecent[i] < leastrecent[flag])
			flag = i;
	return flag;
}
void LRU(){
	int MAX_FRAME, CURR_FRAME = 1;
	cin >> MAX_FRAME;
	int frame;
	int Write, Page;
	int virtualpage;
	int pagefault = 0, transfer = 0;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	long long int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inp",ios::in);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return ;
    }
    long long int time = stdtime + 1;
    intitialise();
	while(!st.eof()){
			st >> Write >> Page;
			if(Write == 1)                         							
				PageTable[Page].entry[1] = 1;   							// if write,  modified bit = 1
			PageTable[Page].entry[2] = 1;       							// reference bit = 1 
			LRU_VECTOR[Page] = time - stdtime;
			//cout <<"time : " <<  LRU_VECTOR[Page] << endl;
			if(PageTable[Page].entry[0]){
				cout << "Page Found" << endl;
	
			}
			else{
				cout << "Page Fault" << endl;
				pagefault++;
				if(CURR_FRAME <= MAX_FRAME){
					// Move page to CURR_FRAME
					PageTable[Page].entry[0] = 1;   							// valid bit
					// set frame number in page in PageTable
					frmbit = CURR_FRAME;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					cout << "IN" << Page << "  "<<CURR_FRAME << endl;
					transfer++;
					cout << "MAP" << Page << "  " << CURR_FRAME << endl;
					cycle+=3000+250;

					CURR_FRAME++;
				}
				else{
					page = LRU_UTIL(LRU_VECTOR);
					temp = PageTable[page].entry;
					temp >>= 3;
					frame = (int)temp.to_ulong();
					LRU_VECTOR[page] = INF;

					cout << "UNMAP " << page << " " << frame << endl;
					if(PageTable[page].entry[1] == 1){
						cout << "OUT" << page << " " << frame << endl;
						cycle+=3000;
						transfer++;
					}
					cout << "IN  " << Page << " " << frame << endl;
					transfer++;
					cout << "MAP " << Page << " " << frame << endl;
					cycle+=250+3000+250;

					PageTable[Page].entry[0] = 1;   						// valid bit
					PageTable[page].entry = 0;                       
					// set frame number in page in PageTable
					frmbit = frame;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
				}

			}
			print(MAX_FRAME);
			time++;
		}

	cout << endl;
	cout << "Cycles " << cycle << endl;
	cout << "Page Faults " << pagefault << endl;
	cout << "Page transfer " << transfer << endl;
	st.close();
}

int NRU_UTIL(int page){
	for(int i = page; i < page + 65; i++){
		if(i%65 == 0)continue;
		if(PageTable[i%65].entry[0] == 1 && PageTable[i%65].entry[2] == 0)
			return i%65;
	}
	for(int i = 1; i < 65; i++)
		PageTable[i].entry[2] = 0;

	for(int i = page; i < page + 65; i++){
		if(i%65 == 0)continue;
		if(PageTable[i%65].entry[0] == 1 && PageTable[i%65].entry[2] == 0)
			return i%65;
	}
}

void NRU(){
	int MAX_FRAME, CURR_FRAME = 1;
	cout << "Frame size" << endl;
	cin >> MAX_FRAME;
	int frame;
	int pagefault = 0;
	int transfer = 0;
	int Write, Page;
	int virtualpage;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	long long int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page = 1;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inp",ios::in);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return ;
    }

	int count = 0;
	intitialise();
	while(!st.eof()){
			// cin >> Write >> Page;
			st >> Write >> Page;  // Step 4: Reading from file
			if(Write == 1)                         							
				PageTable[Page].entry[1] = 1;   							// if write,  modified bit = 1
			PageTable[Page].entry[2] = 1;       							// reference bit = 1
			cycle++; 
			if(PageTable[Page].entry[0]){
				cout << "Page Found " << endl;
			}
			else{
				cout << "Page Fault" << endl;
				pagefault++;
				if(CURR_FRAME <= MAX_FRAME){
					// Move page to CURR_FRAME
					PageTable[Page].entry[0] = 1;   // valid bit
					// set frame number in page in PageTable
					frmbit = CURR_FRAME;
					frmbit <<= 3;
					frmbit[0] = 1;
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
					cout << "IN" << Page << "  "<<CURR_FRAME << endl;
					transfer++;
					cout << "MAP" << Page << "  " << CURR_FRAME << endl;
					cycle+=3000+250;
					CURR_FRAME++;
					count++;

					// if(count == MAX_FRAME){
					// 	//do reference bit = 0
					// 	for(int i = 0; i < 65; i++)
					// 		PageTable[i].entry[2] = 0;
					// }
				}
				else{
					count++;
					// if(count == MAX_FRAME){
					// 	//do reference bit = 0
					// 	for(int i = 0; i < 65; i++)
					// 		PageTable[i].entry[2] = 0;
					// }
					page = NRU_UTIL(page);
					temp = PageTable[page].entry;
					temp >>= 3;
					frame = (int)temp.to_ulong();

					cout << "UNMAP " << page << " " << frame << endl;
					if(PageTable[page].entry[1] == 1){
						cout << "OUT" << page << " " << frame << endl;
						transfer++;
						cycle+=3000;
					}
					cout << "IN  " << Page << " " << frame << endl;
					transfer++;
					cout << "MAP " << Page << " " << frame << endl;
					cycle+=250+3000+250;
					PageTable[page].entry = 0;  
					PageTable[Page].entry[0] = 1;				// valid bit set to 1
					// set frame number in page in PageTable
					frmbit = frame;
					frmbit <<= 3;
					frmbit[0] = PageTable[Page].entry[0];
					frmbit[1] = PageTable[Page].entry[1];
					frmbit[2] = PageTable[Page].entry[2];
					PageTable[Page].entry = frmbit;
					FIFO_QUEUE.push(Page);
				}

			}
			 print(MAX_FRAME);
		}
		cout << endl;
		cout << "Cycles " << cycle << endl;
		cout << "Page Faults " << pagefault << endl;
		cout << "Page transfer " << transfer << endl;
		st.close();

}

int main(){
	int frame;
	int Write, Page;
	int virtualpage;
	int line = 1;
	int i;
	vector<long long int> LRU_VECTOR(65, INF);
	srand(0);
	int cycle = 0;
	bitset<32> temp;
	bitset<32> frmbit;
	int page;
	long long int stdtime = time(0);
	fstream st; // step 1: Creating object of fstream class
    st.open("inpe",ios::out);   // Step 2: Creating new file
    if(!st) // Step 3: Checking whether file exist
    {
        cout<<"No such file";
        return 0;
    }
    int x = 1, y = 2;
    int count = 1;
    vector<int> q;
    int flag = 0;
    int z;
    for(int i = 0; i < 1000000; i++){
    	flag = 0;
    	x = rand() % 2;
    	y = ( rand() + 1 ) % 65;
    	if(q.size() < 9){
    		st << x <<" " <<  y;
    		st << endl;
    		q.push_back(y);
    	}
    	else{
    		z = rand() % 101;
    		if(z < 100){
    			// 99% chnace
    			x = rand() % 2;
    			y = q[rand()%10];
    			st  << x <<" "<< y << endl;
    		}
    		else{
    			x = rand() % 2;
    			y = (rand()+1) % 65;
    			for(int i = 1; i <= 64; i++){
    				for(int j = 0; j < 10; j++)
    					if(q[j] == i){
    						flag = 1;
    						break;
    					}
    				if(flag)continue;
    				else{
    					st  << x <<" "<< y << endl;
    					break;
    				}
    			}
    		}
    	}
    }
	// FIFO
	cout << ".................................FIFO......................................." << endl;
	FIFO();
	cout << endl;
	cout << "................................RANDOM......................................." << endl;
	RANDOM();
	cout << endl;
	cout << "..................................LRU......................................." << endl;
	LRU();
	cout << endl;
	cout << "..................................NRU........................................" << endl;
	NRU();
	cout << endl;
	cout << "............................Second Chance...................................." << endl;
	SecondChance();
	cout << endl;

}