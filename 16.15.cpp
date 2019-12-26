// If there's no reason to provide public interface to the content of Screen, we
// need to make input and output operators both Screen's friend.
// We can make these operators inline non-template friend, or we can difine them
// as operator templates and friend a full specialization in the class
// definition.
