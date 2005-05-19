#ifndef __MINODELINK_H
#define __MINODELINK_H

typedef struct {
  inodeno_t ino;
  int from;
} MInodeLink_st;

class MInodeLink : public Message {
  MInodeLink_st st;

 public:
  inodeno_t get_ino() { return st.ino; }
  int get_from() { return st.from; }

  MInodeLink() {}
  MInodeLink(inodeno_t ino, int from) :
	Message(MSG_MDS_INODELINK) {
	st.ino = ino;
	st.from = from;
  }
  virtual char *get_type_name() { return "InL";}
  
  virtual void decode_payload(crope& s, int& off) {
	s.copy(off, sizeof(st), (char*)&st);
	off += sizeof(st);
  }
  virtual void encode_payload(crope& s) {
	s.append((char*)&st,sizeof(st));
  }
};

#endif
