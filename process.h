class Group;
class Message;

class Process
{
	private:

	// int group_id;
	int process_id;

	typedef struct thread_args
	{
		Process* receiver;
		Process* sender;
		Message message;

	} ThreadArgs;

	vector<int> other_members;
	vector<bool> checked;

	public:

	Process(int id);

	void init_check_array();

	void send_check_p1();

	void check_failure_p1();

	void send_atomic_broadcast_p1(Message m);

	static void* atomic_broadcast_thread_helper(void* args);

	void receive_atomic_broadcast_p1(Process* sender, Message m);

	int get_process_id() const;

	bool operator==(const Process rhs);
};