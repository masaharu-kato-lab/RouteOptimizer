#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "Position.h"
#include "Color.h"
   
namespace ro::iu {

       
//	Bitmap class
	class Bitmap {  
	private:
		using Byte = uint8_t;
		using ByteIndex = uint32_t;
		using PosType = uint32_t;
		
		uint32_t width;
		uint32_t height;

	public:
	//	Main data
	//	std::unique_ptr<Color[]> data;
		Color* data = nullptr;

	public:

	//	Create empty bitmap with specified width and height
		Bitmap(uint32_t width, uint32_t height) noexcept;

	//	Create bitmap from existing data
		Bitmap(uint32_t width, uint32_t height, Color* data_ptr);

	//	Load from file
		Bitmap(std::string filename);
		
	//	Load from binary input stream
		Bitmap(std::istream& is);
		
	//	Load from binary input stream
		Bitmap(std::istream&& is);
      
	//	Deconstructor
		~Bitmap();

	//	Get color (const)
		Color get(Position) const;

	//	Get color
		Color& get(Position);

	//	Set color
		void set(Position, Color c);

	//	Reset with single color
		void reset(Color c);
		
	//	Get width
		uint32_t getWidth() const noexcept; 
		
	//	Get height
		uint32_t getHeight() const noexcept;  

	//	Output to binary output stream
		void output(std::ostream& os) const;
		
	//	Output to file
		void output(std::string filename) const;

	//	Calculate bitmap file size
		ByteIndex calcFileSize() const noexcept;

	//	Calculate data size ( = width * height)
		ByteIndex calcDataSize() const noexcept;

	//	Check the position is inside of image
		bool isInside(Position) const noexcept;

	private:
		constexpr static ByteIndex FILE_HEADER_SIZE = 14;
		constexpr static ByteIndex INFO_HEADER_SIZE = 40;
		
		ByteIndex getByteIndex(Position) const;
		
		void inputFileHeader(std::istream& os);
		void inputInfoHeader(std::istream& os);

		void outputFileHeader(std::ostream& os) const;
		void outputInfoHeader(std::ostream& os) const;

		ByteIndex calcDataOffset() const noexcept;
	};

}
