#include "samurai.hpp"

TeeBuf::TeeBuf(streambuf* sb1, streambuf* sb2): sb1(sb1), sb2(sb2) {}

int TeeBuf::overflow(int c) {
  if (c == EOF) {
    return !EOF;
  } else {
    int const r1 = sb1->sputc(c);
    int const r2 = sb2->sputc(c);
    return r1 == EOF || r2 == EOF ? EOF : c;
  }
}
    
int TeeBuf::sync() {
  int const r1 = sb1->pubsync();
  int const r2 = sb2->pubsync();
  return r1 == 0 && r2 == 0 ? 0 : -1;
}   

TeeStream::TeeStream(ostream& os1, ostream& os2):
  os1(os1), os2(os2),
  ostream(&tbuf), tbuf(os1.rdbuf(), os2.rdbuf()) {}

TeeStream& TeeStream::flush() {
  os1.flush();
  os2.flush();
  return *this;
}

int NullBuf::overflow(int c) {
  return c;
}

NullStream::NullStream() {}



