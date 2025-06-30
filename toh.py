from timeit import default_timer as timer

def TOH(n, src, dst, tmp):
    if n == 1:
        print(f'Move disk {n} from {src} to {dst}')
    else:
        TOH(n-1,src,tmp,dst)
        print(f'Move disk {n} from {src} to {dst}')
        TOH(n-1,tmp, dst, src)

n = int(input("Enter number of disks "))
t1 = timer()
TOH(n,'A','C','B')
t2 = timer()
print(f'Time taken is {t2-t1} seconds')
