#ifndef FACADE_H_INCLUDED
#define FACADE_H_INCLUDED

class CFacade{
  public:
    void EncodeData( CStreamReader&, CStreamWriter& );
    void DecodeData( CStreamReader&, CStreamWriter& );
};


#endif //FACADE_H_INCLUDED
