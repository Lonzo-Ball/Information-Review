网络相关命令：
    1.netstat  查看网络状态的重要工具
	1.n 拒绝显示别名，能显示数字的全部转化成数字
	2.l 仅列出在listen的服务状态
	3.p 显示建立相关链接的程序名
	4.t 仅显示tcp相关选项
	5.u 仅显示udp相关选项
	6.a 显示所有选项，默认不显示listen相关
    2.关闭防火墙  sudo service iptables stop
    3.pidof [进程名]  通过进程名，查看进程id 查看服务器的进程id时非常方便
    4.查看路由表命令  route
    5.ifconfig  查看IP地址、MAC地址、MTU值
    6.arp -a  查看存储 IP地址-MAC地址 的缓存表
    7.cat /etc/hosts  查看hosts文件
    8.ping命令  查看网络的畅通性
    9.traceroute命令  "跟踪"
	
