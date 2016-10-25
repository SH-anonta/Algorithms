//task scheduling problem: Given a set of tasks and their start and end time
//find the maximum number of tasks that can be done if no more than one job can be done at the same time
//meaning no two selected jobs/tasks can have overlapping time
//
//0.Greedy approach: sort the tasks by their end time,
//1. select job that ends first,
//2. skip all jobs that overlap with the current job\
//3. repeat from step 1 until 

/*  Inputs
n Number of tasks, n lines follow with start and end time of ith task
start and end time are in hours where 1 means 1st hour 5 means 5th hour
so a you cant take a task that starts at 2 if your previous task end at 2

6
1 3
1 2
2 6
4 4
5 5
3 6
 
5
1 1
2 4
2 3
1 3
4 6

5
1 3 
2 4 
3 5 
4 6  
5 7
 
 */

#include <utility>
#include <iostream>
#include <cstdio>
#include <algorithm>

//pair: first= start time, second= end time
typedef std::pair<int,int> task_time;

//return if task a ends before task b does
bool comp_tasks_by_endtime(task_time& a, task_time& b){
    return a.second < b.second;
}


//pair first= start time, second= end time, n= size of array, selected tasks tasks selected
int max_tasks(task_time tasks[], int n, std::vector<task_time>& selected_tasks){
    int mx= 1;

    sort(tasks, tasks+n, comp_tasks_by_endtime);
    int current_task_end= tasks[0].second;
    selected_tasks.push_back(tasks[0]);
    
    for(int i= 0; i<n; i++){
        //skip tasks that overlap with current task
        if(current_task_end >= tasks[i].first) continue;
        
        current_task_end= tasks[i].second;
        selected_tasks.push_back(tasks[i]);
        mx++;
    }
    
    return mx;
}


int main(void)
{
    using namespace std;
    
    int n;
    //store start and end time of all tasks
    task_time tasks[100];
    
    cin>>n;
    for(int i= 0; i<n; i++){
        cin>>tasks[i].first>>tasks[i].second;
    }
    
    std::vector<task_time> selected_tasks;
    int mx= max_tasks(tasks, n, selected_tasks);
    
    //view max doable task count and selected tasks
    cout<< mx <<endl;
    for(int i= 0; i<mx; i++){
        cout<< i <<") "<< selected_tasks[i].first << " " << selected_tasks[i].second <<endl;
    }
    
    return 0;
}
