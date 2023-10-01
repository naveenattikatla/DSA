#include<iostream>
#include<list>
using namespace std;
class Youtubechannel{
	private:
		string Name ;
		string ownerName;
		int subscribersCount  = 0 ;
		list<string> publishedVideos;
	protected : 
		int quantity;
	public:
	Youtubechannel(){}
	Youtubechannel(string Name , string ownerName){
		this->Name = Name;
		this->ownerName = ownerName;
	}
	void getInfo(){
		cout<<"Channel Name "<<Name<<endl;
		cout<<"Owner Name "<<ownerName<<endl;
		cout<<"Subscriber count "<<subscribersCount<<endl;
		for(string videos : publishedVideos){
			cout<<videos<<endl;
		}
	}
	void add_a_video(string video){
		publishedVideos.push_back(video);
	}
	void setQuantity(int quantity){
		this->quantity = quantity;
	}
	void subscribe(){
		subscribersCount++;
	}
	void unsubscribe(){
		if(subscribersCount > 0)
			subscribersCount--;
	}
			
};
class cookieYtChanner : public Youtubechannel{
	public:
		cookieYtChanner(string name , string ownername) : Youtubechannel(name , ownername){
			cout<<"cookieYtChanner "<<endl;
		}
		void practice(){
			cout<<"cooking is an art..."<<endl;
		}
};
int main(){
	Youtubechannel ytchannel("Telusko","Navin reddy");
	ytchannel.subscribe();
	ytchannel.subscribe();
	ytchannel.subscribe();
	ytchannel.add_a_video("Block chain");
	ytchannel.add_a_video("Core Java for beginners");
	ytchannel.getInfo();
	
	cout<<endl;
	
	cookieYtChanner ckytchannel("any`s kichen","First video");
	ckytchannel.getInfo();
	ckytchannel.setQuantity(4);

	return 0;
}