











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
