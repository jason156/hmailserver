// Copyright (c) 2005 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com
// Created 2006-03-25
//

#pragma once

namespace HM
{
   class ByteBuffer;

   class File  
   {
   public:
	   File();
	   virtual ~File();

      enum OpenType
      {
         OTReadOnly = 1,
         OTCreate = 2,
         OTAppend = 3,
      };

      enum Constants
      {
         FileChunkSize = 15000
      };

      bool IsOpen() const;
      bool Open(const String &sFilename, OpenType ot);

      void Close();
      
      bool Write(const String &sWrite);
      bool Write(const AnsiString &sWrite);
      bool Write(const unsigned char *pBuf, int iBufLen, DWORD &dwNoOfBytesWritten);
      bool Write(std::shared_ptr<ByteBuffer> pBuffer, DWORD &dwNoOfBytesWritten);
      bool Write(File &sourceFile);
      bool WriteBOF();

      int GetSize();

      std::shared_ptr<ByteBuffer> ReadFile();
      std::shared_ptr<ByteBuffer> ReadTextFile();
      std::shared_ptr<ByteBuffer> ReadChunk(int iMaxSize);

      String GetName() const;

   private:
      
      FILE * file_;
      String name_;
   };

}
