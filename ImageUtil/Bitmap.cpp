#include "bitmap.h"
#include <fstream>
#include <stdexcept>
#include <xutility>
#include "binary_io.h"

using namespace imgutil;

Bitmap::Bitmap(uint32_t width, uint32_t height) noexcept
	: width(width), height(height) /* , data(new Color[calcDataSize()]) */
{
	auto size = calcDataSize();
	data = new Color[size];
}

Bitmap::Bitmap(uint32_t width, uint32_t height, Color* data_ptr)
	: Bitmap(width, height)
{
	std::copy(data_ptr, data_ptr + sizeof(Color) * calcDataSize(), data/*.get()*/);
}

Bitmap::Bitmap(std::string filename)
	: Bitmap(std::ifstream(filename, std::ios::binary))
{}

Bitmap::Bitmap(std::istream& is)  
{
	inputFileHeader(is);
	inputInfoHeader(is);
//	data.reset(new Color[calcDataSize()]);
	data = new Color[calcDataSize()];
	is.read((char*)data /*.get()*/, sizeof(Color) * calcDataSize());
}  

Bitmap::Bitmap(std::istream&& is)
	: Bitmap((std::istream&)is)
{}

Bitmap::~Bitmap()
{
	delete[] data;
}

auto Bitmap::getByteIndex(Position p) const -> ByteIndex
{
#ifdef _DEBUG
	if(!isInside(p)) throw std::exception("Position is out of range.");
#endif
	auto index = width * (height - 1 - p.y) + p.x;
//	ByteIndex ret = width * p.y + p.x;
	if(index >= calcDataSize()) throw std::exception("Byte index is out of range.");
	return index;
}

bool Bitmap::isInside(Position p) const noexcept
{
	return p.x < width && p.y < height;
}


//	 ビットマップデータのファイル書き出し 
void Bitmap::output(std::ostream& os) const
{
	outputFileHeader(os);
	outputInfoHeader(os);
	auto data_byte = sizeof(Color) * calcDataSize();

	size_t count = 0;

	//for(uint32_t iy = 0; iy < getHeight(); ++iy) {
	//	for(uint32_t ix = 0; ix < getWidth(); ++ix) {
	//		outputAsBinary(os, data[getByteIndex({ix, iy})]);
	//		++count;
	//	}
	//}

	os.write((char*)data /*.get()*/ , data_byte);
}

void Bitmap::output(std::string filename) const
{
	std::ofstream ofs(filename, std::ios::binary);
	output(ofs);
}

Color Bitmap::get(Position p) const
{
	return data[getByteIndex((Position&&)p)];
}

Color& Bitmap::get(Position p)
{
	return data[getByteIndex((Position&&)p)];
}

void Bitmap::set(Position p, Color color)
{
	get(p) = color;
}

void Bitmap::reset(Color color)
{
	std::fill(data/*.get()*/, data/*.get()*/ + calcDataSize(), color);
}

uint32_t Bitmap::getHeight() const noexcept
{
	return height;
}

uint32_t Bitmap::getWidth() const noexcept
{
	return width;
}

void Bitmap::inputFileHeader(std::istream& is)
{
	uint8_t file_type_1, file_type_2;
	uint32_t file_size, data_offset;

	inputAsBinary(is,
		&file_type_1, &file_type_2,
		&file_size,
		(uint16_t*)nullptr,		//	Reseverd 1
		(uint16_t*)nullptr,		//	Reserved 2
		&data_offset
	);

	if(!(file_type_1 == 'B' && file_type_2 == 'M')) throw std::runtime_error("Unsupported bitmap file type.");
	if(data_offset != calcDataOffset()) throw std::runtime_error("Data offset doesn't match.");

}

void Bitmap::inputInfoHeader(std::istream& is)
{
	uint16_t bits_per_pixel;
	uint32_t info_header_size, compress_type, data_size;

	inputAsBinary(is,
		&info_header_size,		//	the size of this header, in bytes (must be 40)
		&width,					//	the bitmap width in pixels
		&height,				//	the bitmap height in pixels
		(uint16_t*)nullptr,		//	(unused) the number of color planes
		&bits_per_pixel,		//	the number of bits per pixel, which is the color depth of the image (must be 32)
		&compress_type,			//	the compression method being used (must be 0)
		&data_size,				//	the image size, the size of the raw bitmap data
		(uint32_t*)nullptr,		//	(unused) the horizontal resolution of the image
		(uint32_t*)nullptr,		//	(unused) the horizontal resolution of the image
		(uint32_t*)nullptr,		//	(unused) the number of colors in the color palette
		(uint32_t*)nullptr		//	(unused) the number of important colors used
	);

	if(info_header_size != INFO_HEADER_SIZE) throw std::runtime_error("Unsupported information header size.");
	if(bits_per_pixel != 32) throw std::runtime_error("Unsupported color depth (must be 32).");
	if(compress_type != 0) throw std::runtime_error("Compressed bitmap is not supported.");
	if(data_size != calcDataSize()) throw std::runtime_error("Data size doesn't match.");

}

void Bitmap::outputFileHeader(std::ostream& os) const
{
	outputAsBinary(os,
		'B', 'M',			//	File type
		calcFileSize(),		//	File size
		uint16_t(0),		//	Reseverd 1
		uint16_t(0),		//	Reserved 2
		calcDataOffset()	//	Offset to image data
	);
}

void Bitmap::outputInfoHeader(std::ostream& os) const
{
	outputAsBinary(os,
		INFO_HEADER_SIZE,	//	the size of this header, in bytes (40)
		width,				//	the bitmap width in pixels
		height,				//	the bitmap height in pixels
		uint16_t(1),		//	the number of color planes (must be 1)
		uint16_t(32),		//	the number of bits per pixel, which is the color depth of the image (Typical values: 1, 4, 8, 16, 24, 32)
		uint32_t(0),		//	the compression method being used
		calcDataSize(),		//	the image size, the size of the raw bitmap data
		uint32_t(0),		//	the horizontal resolution of the image (in pixel per metre)
		uint32_t(0),		//	the horizontal resolution of the image (in pixel per metre)
		uint32_t(0),		//	the number of colors in the color palette
		uint32_t(0)			//	the number of important colors used (generally ignored)
	);
}

auto Bitmap::calcDataSize() const noexcept -> ByteIndex 
{
	return width * height;
}

auto Bitmap::calcFileSize() const noexcept -> ByteIndex
{
	return calcDataOffset() + calcDataSize();
}

auto Bitmap::calcDataOffset() const noexcept -> ByteIndex
{
	return FILE_HEADER_SIZE + INFO_HEADER_SIZE;
}