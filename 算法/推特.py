


class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        1.用双端队列初始化推特
        2.并初始化最大时间戳，用来标识推特发布的先后顺序 
        3.用集合初始化推文
        4.注意，本class的实例对象为twitter，并非推特使用者
        """
        self.twitter=collections.defaultdict(collections.deque)            
        self.followList=collections.defaultdict(set)
        self.timestamp=2**31

    def postTweet(self, userId:int, tweetId:int)->None:
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        ?默认的dict索引有多大
         1.将(self.timestamp,tweetId)组成元组放入队列中 tweetId即为报文id
         2.appendleft的原因是要维持队列有序
        """
        
        self.timestamp-=1
        self.twitter[userId].appendleft((self.timestamp,tweetId))
        

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        1.根据用户关注的推特用户id和自己的id得到推特报文
        2.返回的迭代器是指向排序的元组，按理来说是按照timestamp排序的
        3.返回twIter中前十个元素(因在merge的时候就已经排序)
        """
        twIter=heapq.merge(*(self.twitter[u] for u in self.followList[userId]|{userId}))
        return  [t  for _,t in  itertools.islice(twIter,10) ]


    def follow(self, followerId, followeeId)->None:
        self.followList[followerId].add(followeeId)

        

    def unfollow(self, followerId, followeeId)->None:
        self.followList[followerId].discard(followeeId)











class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tweets=collections.defaultdict(collections.deque)
        self.followlist=collections.defaultdict(set)
        self.timestamp=2**31
    def postTweet(self, userId:int, tweetId:int)->None:
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.timestamp-=1
        self.tweets[userId].appendleft((self.timestamp,tweetId))
        
        """
        ->表示捕获
        """
    def getNewsFeed(self, userId)->int:                  
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        tweets = heapq.merge(*(self.tweets[u] for u in self.followlist[userId] | {userId}))
        return [t for _, t in itertools.islice(tweets, 10)]

    def follow(self, followerId, followeeId)->None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        self.followlist[followerId].add(followeeId)
        

    def unfollow(self, followerId, followeeId)->None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        self.followlist[followerId].discard(followeeId)
