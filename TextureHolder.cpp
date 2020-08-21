#include "TextureHolder.h"
// Include the "assert feature"
#include <assert.h>

TextureHolder* TextureHolder::member_static_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(member_static_Instance == nullptr); //Make sure it is set to nullPtr. If it has something, assert will end the program. Singleton.
	member_static_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename)
{
	// Get a reference to m_Textures using m_s_Instance
	auto& mapOfTextures = member_static_Instance->member_map_Textures;
	// auto is the equivalent of map<string, Texture>
	// Create an iterator to hold a key-value-pair (kvp)
	// and search for the required kvp
	// using the passed in file name
	auto keyValuePair = mapOfTextures.find(filename);
	// auto is equivalent of map<string, Texture>::iterator
	// Did we find a match?
	if (keyValuePair != mapOfTextures.end())
	{
		// Yes
		// Return the texture,
		// the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
		// File name not found
		// Create a new key value pair using the filename
		//Texture& texture = mapOfTextures[filename];  //mapOfTextures is of type map<string, Texture>
		auto& texture = mapOfTextures[filename];  //mapOfTextures is of type map<string, Texture>		
		// Load the texture from file in the usual way
		texture.loadFromFile(filename);
		// Return the texture to the calling code
		return texture;
	}
}