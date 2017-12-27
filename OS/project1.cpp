

SYSCALL_DEFINE5(mysetnice,pid_t,pid,int,flag,int,nice_value,void __user*, prio,void __user*, nice)
{
  struct task_struct* task;
  task = find_task_by_vpid(pid);
  if(flag == 1) {
    set_user_nice(task,nice_value);
  }
  *(int*)nice  = task_nice(task);
  *(int*)prio = NICE_TO_PRIO(*(int*)nice);
  if(*(int*)prio < 0 && *(int*)nice == -1 ) {
    return EFAULT;
  }
  return 0;
}

