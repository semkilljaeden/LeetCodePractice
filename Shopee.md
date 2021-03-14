I.mysql事务的隔离级别有了解吗，每个级别分别有解决了什问题？

ACID: 

try to resolve read-write conflict.

1. read uncommited - only write lock, another transaction can read the data that has not been commited
2. read commited - has version control, only can read the version number associated with the transaction
3. repeatable reading - record lock + gap lock
4. serializable

隔离等级对加锁的影响MySQL 的隔离等级对加锁有影响，所以在分析具体加锁场景时，首先要确定当前的隔离等级。读未提交（Read Uncommitted 后续简称 RU）：可以读到未提交的读，基本上不会使用该隔离等级，所以暂时忽略。读已提交（Read Committed 后续简称 RC）：存在幻读问题，对当前读获取的数据加记录锁。可重复读（Repeatable Read 后续简称 RR）：不存在幻读问题，对当前读获取的数据加记录锁，同时对涉及的范围加间隙锁，防止新的数据插入，导致幻读。序列化（Serializable）：从 MVCC 并发控制退化到基于锁的并发控制，不存在快照读，都是当前读，并发效率急剧下降，不建议使用。这里说明一下，RC 总是读取记录的最新版本，而 RR 是读取该记录事务开始时的那个版本，虽然这两种读取的版本不同，但是都是快照数据，并不会被写操作阻塞，所以这种读操作称为 快照读（Snapshot Read）

MySQL 还提供了另一种读取方式叫当前读（Current Read），它读的不再是数据的快照版本，而是数据的最新版本，并会对数据加锁，根据语句和加锁的不同，又分成三种情况：SELECT ... LOCK IN SHARE MODE：加共享(S)锁SELECT ... FOR UPDATE：加排他(X)锁INSERT / UPDATE / DELETE：加排他(X)锁当前读在 RR 和 RC 两种隔离级别下的实现也是不一样的：RC 只加记录锁，RR 除了加记录锁，还会加间隙锁，用于解决幻读问题。


Lock:
table lock, row lock --> can use intent lock to indicate that this table has a row lock instead of searching every row



II. WebSoccket, how to achieve persistent connection:
    1. HTML5 new tech aim for long connection
    2. Normal HTML: Non-persistent, One Request, One Response then the connection completes
    2. other choices: short poll -> keep asking again and again   ->server needs to have fast speed
                      long poll-> no response to client until data is ready   -> since all connection is alive, needs enough port/handler
    3. websocket: server could actively sends message to client, no need to have a request/response pattern
    4. connection can be established between handler and the client
    5. http is stateless, need to redo indentification/metadata every connection



III.乐观锁&悲观锁，乐观锁与悲观锁的实现方式？

Passive:Mutex, block other people
Optimistic: CAS, version number (a thread may keep retrying to save, self spinning) ABA problem

IV self spin, mutex
1.self spin, keep trying to acquire lock --- no context switching
2. thread yield and go to sleep, let OS to wake it up ---- context switching

Fair vs Unfair：
Fair: FIFO
Unfair: faster thread can get the lock, slow thread may stave

Deadlock:

1. target can only be acquire once  --- read 
2. No willingly give up, hold and wait --- timeout mechanism
3. cannot forcely acquire
4. loop condition   --- make the lock acquiring order all the same



索引的实现方式有哪些？(B+树索引、位图索引、哈希索引)

    哈希索引不适用的场景：不支持范围查询不支持索引完成排序不支持联合索引的最左前缀匹配规则通常，B+树索引结构适用于绝大多数场景，像下面这种场景用哈希索引才更有优势：在HEAP表中，如果存储的数据重复度很低（也就是说基数很大），对该列数据以等值查询为主，没有范围查询、没有排序的时候，特别适合采用哈希索引




讲一下B+树的实现原理，为什么要用B+树？

    数据记录本身被存于主索引（一颗B+Tree）的叶子节点上，这就要求同一个叶子节点内（大小为一个内存页或磁盘页）的各条数据记录按主键顺序存放因此每当有一条新的记录插入时，MySQL会根据其主键将其插入适当的节点和位置，如果页面达到装载因子（InnoDB默认为15/16），则开辟一个新的页（节点）3、如果表使用自增主键，那么每次插入新的记录，记录就会顺序添加到当前索引节点的后续位置，当一页写满，就会自动开辟一个新的页4、如果使用非自增主键（如果身份证号或学号等），由于每次插入主键的值近似于随机，因此每次新纪录都要被插到现有索引页得中间某个位置此时MySQL不得不为了将新记录插到合适位置而移动数据，甚至目标页面可能已经被回写到磁盘上而从缓存中清掉，此时又要从磁盘上读回来，这增加了很多开销同时频繁的移动、分页操作造成了大量的碎片，得到了不够紧凑的索引结构，后续不得不通过OPTIMIZE TABLE来重建表并优化填充页面。



Hashmap了解吗？红黑树讲一讲，为什么用红黑树？

    loading factor 0.75 -> reach then capacity doubled

    hashcode

    hash collision


    1.节点是红色或黑色。
    根是黑色。
    所有叶子都是黑色（叶子是NIL节点）。
    每个红色节点必须有两个黑色的子节点。（从每个叶子到根的所有路径上不能有两个连续的红色节点。）
    从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点（简称黑高）。

        不严格是因为它不是严格控制左、右子树高度或节点数之差小于等于1。
    但红黑树高度依然是平均log(n)，且最坏情况高度不会超过2log(n)，这有数学证明。所以它算平衡树，只是不严格。不过严格与否并不影响数据结构的复杂度。
    不用严格控制高度，使得插入效率更高。



CAP：

    Consistency, Availability, Partition Tolerance

    从客户端角度，多进程并发访问时，更新过的数据在不同进程如何获取的不同策略，决定了不同的一致性。强一致性   对于关系型数据库，要求更新过的数据能被后续的访问都能看到，这是强一致性。弱一致性   如果能容忍后续的部分或者全部访问不到，则是弱一致性。最终一致性   如果经过一段时间后要求能访问到更新后的数据，则是最终一致性。






缓存有用过哪一些？radis了解吗？

    No. Couchbase. 数据存储：nosql，易水平扩展。

    缓存层：低水位和高水位设置，文档metadata。

    vBucket：使系统易于动态管理，自动分片，reblancing。

    多线程持久化：预分配每个线程的访问范围，保证性能和可靠性。

    支持 SQL 的这样一类系统，例如 MySQL，一般支持事务不同的隔离级别， QPS 要求比较高，延时比较低，主要用于交易信息和关键数据的存储，比如订单、VIP 信息等。

    左下角是 NoSQL 数据库，是一类针对特殊场景做优化的系统，schema 一般比较简单，吞吐量较高、延迟较低，一般用作缓存或者 KV 数据库。


NoSQL vs SQL:

    1、Data相关性极低
    Data非常不relational (require no join or few joins)，这时用SQL 就有点浪费，可能会有不必要的overhead。

    2、Data相关性极高
    这时用CF NoSQL可能要处理大量的de-normalization，虽然disk便宜，但duplicated data太多的话可能也会爆容量。而且update时要处理de-norm data间consistency的问题。


进程与线程的区别？

    每个进程(应用App)相当于一个容器，所有应用App里面需要的资源和机制都在进程里面。

    线程是OS独立调度执行的单元，OS调度执行的单位就是线程，线程需要以进程作为容器和使用进程相关的环境。


    每个线程共享进程的代码段内存空间，所以我们编写多线程代码的时候，可以在任何线程调用任何函数。每个线程共享进程的数据段内存空间，所以我们编写多线程代码的时候，可以在任何线程访问全局变量。每个线程共享进程的堆，所以我们编写多线程代码的时候，可以在一个线程访问另外一个线程new/malloc出来的内存对象。每个线程都有自己的栈的空间，所以可以独立调用执行函数（参数，局部变量，函数跳转）相互之间不受影响。


    初始化
    可运行
    运行中
    阻塞
    销毁


了解协程吗？

    https://www.zhihu.com/search?type=content&q=%E5%8D%8F%E7%A8%8B

    协程不是被操作系统内核所管理，而完全是由程序所控制 ---------------------IO



    协程，又称微线程，纤程。英文名Coroutine。一句话说明什么是线程：协程是一种用户态的轻量级线程。


    协程拥有自己的寄存器上下文和栈。协程调度切换时，将寄存器上下文和栈保存到其他地方，在切回来的时候，恢复先前保存的寄存器上下文和栈。因此：
    协程能保留上一次调用时的状态（即所有局部状态的一个特定组合），每次过程重入时，就相当于进入上一次调用的状态，换种说法：进入上一次离开时所处逻辑流的位置。


    协程的好处：

    无需线程上下文切换的开销
    无需原子操作锁定及同步的开销
    方便切换控制流，简化编程模型



同步与异步
    https://zhuanlan.zhihu.com/p/70256971
    同步是阻塞模式，异步是非阻塞模式。

    同步就是指一个进程在执行某个请求的时候，若该请求需要一段时间才能返回信息，那么这个进程将会一直等待下去，知道收到返回信息才继续执行下去；
    异步是指进程不需要一直等下去，而是继续执行下面的操作，不管其他进程的状态。当有消息返回式系统会通知进程进行处理，这样可以提高执行的效率。


进程之间的通信方式？
    管道(pipe)
    消息队列
    共享内存


线程之间的同步方式?(锁,信号量)

锁



进程调度算法？

    先来先服务调度算法FCFS
    短作业（进程）优先调度算法SJF
    高响应比优先调度算法HRRN
    基于时间片的轮转调度算法RR
    多级反馈队列算法FB


    协作式多任务：多个进程独立运行，但每个进程都要发扬风格，不执行规模过大的计算；或者执行规模较大的计算时，每隔一段时间主动调用一下OS提供的特定API，让出控制权给其它进程。总之，人之初，性本善。每个人都替别人着想，世界就会很美好。那万一出个恶人、病人呢？世界崩塌了。抢夺式多任务：系统里跑的程序，有的是坏人写的，也有的会意外病倒。操作系统要监控所有进程，公平分配CPU时间片等资源给每个应用；如果一个应用用完了自己的份额，那么操作系统就要强制暂停它的执行，保存它的执行现场，把CPU安排给另一个进程——从而避免坏进程/病态进程影响系统的正常运行。





什么叫死锁？死锁的必要条件？如何处理死锁问题？

    Deadlock:

    1. target can only be acquire once  --- read 
    2. No willingly give up, hold and wait --- timeout mechanism
    3. cannot forcely acquire
    4. loop condition   --- make the lock acquiring order all the same



计算机网络七层结构？每一层主要做什么？http(application)、tcp(transport) 分别属于哪一层？

https://www.zhihu.com/search?type=content&q=%E4%B8%89%E6%AC%A1%E6%8F%A1%E6%89%8B

    TCP/IP是一个四层的体系结构，主要包括：应用层、运输层、网际层和网络接口层。五层协议的体系结构主要包括：应用层、运输层、网络层(IP)，数据链路层和物理层。OSI七层协议模型主要包括是：应用层（Application）、表示层（Presentation）、会话层（Session）、运输层（Transport）、网络层（Network）、数据链路层（Data Link）、物理层（Physical

    传输控制协议-TCP：提供面向连接的，可靠的数据传输服务。
    用户数据协议-UDP：提供无连接的，尽最大努力的数据传输服务（不保证数据传输的可靠性）。


ARP to find MAC


http的状态码有哪些?

200 ok 500 internal error, 503 unavailable, 404 not found
get与post的区别？

    GET和POST区别Get是不安全的，因为在传输过程，数据被放在请求的URL中；Post的所有操作对用户来说都是不可见的。 但是这种做法也不时绝对的，大部分人的做法也是按照上面的说法来的，但是也可以在get请求加上 request body，给 post请求带上 URL 参数。Get请求提交的url中的数据最多只能是2048字节，这个限制是浏览器或者服务器给添加的，http协议并没有对url长度进行限制，目的是为了保证服务器和浏览器能够正常运行，防止有人恶意发送请求。Post请求则没有大小限制。Get限制Form表单的数据集的值必须为ASCII字符；而Post支持整个ISO10646字符集。Get执行效率却比Post方法好。Get是form提交的默认方法。GET产生一个TCP数据包；POST产生两个TCP数据包。对于GET方式的请求，浏览器会把http header和data一并发送出去，服务器响应200（返回数据）；而对于POST，浏览器先发送header，服务器响应100 continue，浏览器再发送data，服务器响应200 ok（返回数据）。


http与https的区别？https的加密方式？

    公钥私钥, 3rd party authority to authenticate public key

    HTTP协议本身是无状态的。什么是无状态呢，即服务器无法判断用户身份。

tcp三次握手？四次挥手？


    为什么TCP连接的时候是3次？2次不可以吗？因为需要考虑连接时丢包的问题，如果只握手2次，第二次握手时如果服务端发给客户端的确认报文段丢失，此时服务端已经准备好了收发数(可以理解服务端已经连接成功)据，而客户端一直没收到服务端的确认报文，所以客户端就不知道服务端是否已经准备好了(可以理解为客户端未连接成功)，这种情况下客户端不会给服务端发数据，也会忽略服务端发过来的数据。如果是三次握手，即便发生丢包也不会有问题，比如如果第三次握手客户端发的确认ack报文丢失，服务端在一段时间内没有收到确认ack报文的话就会重新进行第二次握手，也就是服务端会重发SYN报文段，客户端收到重发的报文段后会再次给服务端发送确认ack报文。为什么TCP连接的时候是3次，关闭的时候却是4次？因为只有在客户端和服务端都没有数据要发送的时候才能断开TCP。而客户端发出FIN报文时只能保证客户端没有数据发了，服务端还有没有数据发客户端是不知道的。而服务端收到客户端的FIN报文后只能先回复客户端一个确认报文来告诉客户端我服务端已经收到你的FIN报文了，但我服务端还有一些数据没发完，等这些数据发完了服务端才能给客户端发FIN报文(所以不能一次性将确认报文和FIN报文发给客户端，就是这里多出来了一次)。为什么客户端发出第四次挥手的确认报文后要等2MSL的时间才能释放TCP连接？这里同样是要考虑丢包的问题，如果第四次挥手的报文丢失，服务端没收到确认ack报文就会重发第三次挥手的报文，这样报文一去一回最长时间就是2MSL，所以需要等这么长时间来确认服务端确实已经收到了。如果已经建立了连接，但是客户端突然出现故障了怎么办？TCP设有一个保活计时器，客户端如果出现故障，服务器不能一直等下去，白白浪费资源。服务器每收到一次客户端的请求后都会重新复位这个计时器，时间通常是设置为2小时，若两小时还没有收到客户端的任何数据，服务器就会发送一个探测报文段，以后每隔75秒钟发送一次。若一连发送10个探测报文仍然没反应，服务器就认为客户端出了故障，接着就关闭连接。


TCP的TIME_WAIT状态

    客户端“等待2MSL”期间即处于TIME_WAIT状态

    TIME_WAIT状态
    TCP连接中，调用close()发起主动关闭的一方，在发送最后一个ACK之后会进入time_wait的状态，也就说该发送方会保持2MSL时间之后才会回到初始状态。MSL值得是数据包在网络中的最大生存时间。
    后果：在2MSL连接等待期间，本TCP连接定义的四元组（客户端IP地址和端口，服务端IP地址和端口号）不能被使用。
    TIME_WAIT状态的目的
    保证TCP全双工连接可靠释放

    假设主动关闭连接的一方（假设是客户端）最后发送的ACK报文在网络中丢失，服务器会重发FIN报文。在重发的FIN报文到达客户端之前，客户端必须维护连接状态，才能正常进行重传等工作。

    如果没有TIME_WAIT状态，那么当服务器重发的FIN报文到达时，客户端会用RST报文相应，这会让服务器认为出现了异常。

    使旧的数据包在网络中因过期而消失

    TCP连接由 (local_IP, local_port, remote_IP, remote port) 四元组唯一标识，现在假设TIME_WAIT状态不存在的情况：

    客户端主动关闭连接后，未经TIME_WAIT状态，直接重新和服务器再次建立一个新TCP连接，这个新连接的四元组和旧连接相同。如果旧连接的报文阻塞在网络中，直到建立新连接后才到达服务器，由于新旧TCP连接四元组相同，服务器会认为这个旧连接的报文是当前需要的报文，而将其向上传递给应用层，这就会造成数据错乱等问题，破坏TCP的可靠性。

    释放的端口可能会重连刚断开的服务器端口，这样依然存活在网络里的老的TCP报文可能与新TCP连接报文冲突，造成数据冲突



Socket


    UNIX/Linux 中的 socket 是什么？在 UNIX/Linux 系统中，为了统一对各种硬件的操作，简化接口，不同的硬件设备也都被看成一个文件。对这些文件的操作，等同于对磁盘上普通文件的操作。你也许听很多高手说过，UNIX/Linux 中的一切都是文件！那个家伙说的没错。 为了表示和区分已经打开的文件，UNIX/Linux 会给每个文件分配一个 ID，这个 ID 就是一个整数，被称为文件描述符（File Descriptor）。例如：  通常用 0 来表示标准输入文件（stdin），它对应的硬件设备就是键盘； 通常用 1 来表示标准输出文件（stdout），它对应的硬件设备就是显示器。UNIX/Linux 程序在执行任何形式的 I/O 操作时，都是在读取或者写入一个文件描述符。一个文件描述符只是一个和打开的文件相关联的整数，它的背后可能是一个硬盘上的普通文件、FIFO、管道、终端、键盘、显示器，甚至是一个网络连接。请注意，网络连接也是一个文件，它也有文件描述符！必须理解这句话。 我们可以通过 socket() 函数来创建一个网络连接，或者说打开一个网络文件，socket() 的返回值就是文件描述符。有了文件描述符，我们就可以使用普通的文件操作函数来传输数据了，例如：  用 read() 读取从远程计算机传来的数据； 用 write() 向远程计算机写入数据。只要用 socket() 创建了连接，剩下的就是文件操作了，网络编程原来就是如此简单！







消息队列有用过吗？

https://zhuanlan.zhihu.com/p/68052232

    解耦, 异步,  削峰

https://zhuanlan.zhihu.com/p/73475227

    Kafka Zookeeper:
        领导者选举的过程中至少要有三台zkServer投了同一个zkServer，才会符合过半机制，才能选出来一个Leader。



    Broker：Broker是kafka实例，每个服务器上有一个或多个kafka的实例，我们姑且认为每个broker对应一台服务器。每个kafka集群内的broker都有一个不重复的编号，如图中的broker-0、broker-1等……

    Topic：消息的主题，可以理解为消息的分类，kafka的数据就保存在topic。在每个broker上都可以创建多个topic。

    Partition：Topic的分区，每个topic可以有多个分区，分区的作用是做负载，提高kafka的吞吐量。同一个topic在不同的分区的数据是不重复的，partition的表现形式就是一个一个的文件夹！

    Replication:每一个分区都有多个副本，副本的作用是做备胎。当主分区（Leader）故障的时候会选择一个备胎（Follower）上位，成为Leader。在kafka中默认副本的最大数量是10个，且副本的数量不能大于Broker的数量，follower和leader绝对是在不同的机器，同一机器对同一个分区也只可能存放一个副本（包括自己）。

    Message：每一条发送的消息主体。

    Consumer：消费者，即消息的消费方，是消息的出口。

    Consumer Group：我们可以将多个消费组组成一个消费者组，在kafka的设计中同一个分区的数据只能被消费者组中的某一个消费者消费。同一个消费者组的消费者可以消费同一个topic的不同分区的数据，这也是为了提高kafka的吞吐量！

    Zookeeper：kafka集群依赖zookeeper来保存集群的的元信息，来保证系统的可用性。


    1、 方便扩展。因为一个topic可以有多个partition，所以我们可以通过扩展机器去轻松的应对日益增长的数据量。

    2、 提高并发。以partition为读写单位，可以多个消费者同时消费数据，提高了消息的处理效率。

    熟悉负载均衡的朋友应该知道，当我们向某个服务器发送请求的时候，服务端可能会对请求做一个负载，将流量分发到不同的服务器，那在kafka中，如果某个topic有多个partition，producer又怎么知道该将数据发往哪个partition呢？kafka中有几个原则：

    1、 partition在写入的时候可以指定需要写入的partition，如果有指定，则写入对应的partition。

    2、 如果没有指定partition，但是设置了数据的key，则会根据key的值hash出一个partition。

    3、 如果既没指定partition，又没有设置key，则会轮询选出一个partition。

    保证消息不丢失是一个消息队列中间件的基本保证，那producer在向kafka写入消息的时候，怎么保证消息不丢失呢？其实上面的写入流程图中有描述出来，那就是通过ACK应答机制！在生产者向队列写入数据的时候可以设置参数来确定是否确认kafka接收到数据，这个参数可设置的值为0、1、all。

    0代表producer往集群发送数据不需要等到集群的返回，不确保消息发送成功。安全性最低但是效率最高。

    1代表producer往集群发送数据只要leader应答就可以发送下一条，只确保leader发送成功。

    all代表producer往集群发送数据需要所有的follower都完成从leader的同步才会发送下一条，确保leader发送成功和所有的副本都完成备份。安全性最高，但是效率最低。

    最后要注意的是，如果往不存在的topic写数据，能不能写入成功呢？kafka会自动创建topic，分区和副本的数量根据默认配置都是1。

    多个消费者可以组成一个消费者组（consumer group），每个消费者组都有一个组id！同一个消费组者的消费者可以消费同一topic下不同分区的数据，但是不会组内多个消费者消费同一分区的数据！！！是不是有点绕。我们看下图：


    kafka分布式的情况下，如何保证消息的顺序?

    Kafka 中发送1条消息的时候，可以指定(topic, partition, key) 3个参数。partiton 和 key 是可选的。如果你指定了 partition，那就是所有消息发往同1个 partition，就是有序的。并且在消费端，Kafka 保证，1个 partition 只能被1个 consumer 消费。或者你指定 key（比如 order id），具有同1个 key 的所有消息，会发往同1个 partition。也是有序的。


有做过什么项目？做了什么？
有什么想要问我的吗？