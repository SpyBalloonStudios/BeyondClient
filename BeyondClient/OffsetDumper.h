// il2cpp_finder.h
#pragma once

#include <cstdint>
#include <Windows.h>
#include <iostream>
#include <memory>
#include <vector>

#ifdef _WIN64
#define APICALL __fastcall
#else
#define APICALL __cdecl
#endif

class Class;
class Image;

namespace api
{
    inline bool initalized{ false };

    // domain & assembly
    using get_domain_t = void* (APICALL*)(void);
    using get_assemblies_t = void** (APICALL*)(const void* domain, size_t* count);

    inline get_domain_t get_domain = nullptr;
    inline get_assemblies_t get_assemblies = nullptr;

    // images
    using get_image_t = Image * (APICALL*)(const void* assembly);
    using get_image_name_t = const char* (APICALL*)(const void* image);
    using get_class_count_t = size_t(APICALL*)(const void* image);

    inline get_image_t get_image = nullptr;
    inline get_image_name_t get_image_name = nullptr;
    inline get_class_count_t get_class_count = nullptr;

    // class
    using get_class_t = Class * (APICALL*)(const void* image, const char* namespaze, const char* name);
    using get_class_from_id_t = Class * (APICALL*)(const void* image, size_t index);
    using get_class_name_t = const char* (APICALL*)(const void* klass);

    inline get_class_t get_class = nullptr;
    inline get_class_from_id_t get_class_from_id = nullptr;
    inline get_class_name_t get_class_name = nullptr;

    // types
    using get_nested_types_t = Class * (APICALL*)(const void* klass, void*);
    using get_type_class_t = Class * (APICALL*)(const void* type);
    using get_type_name_t = const char* (APICALL*)(const void* type);

    inline get_nested_types_t get_nested_types = nullptr;
    inline get_type_class_t get_type_class = nullptr;
    inline get_type_name_t get_type_name = nullptr;

    // fields
    using get_field_t = void* (APICALL*)(const void* klass, const char* name);
    using get_field_offset_t = size_t(APICALL*)(const void* field);
    using get_field_count_t = size_t(APICALL*)(const void* klass);
    using get_fields_t = void* (APICALL*)(const void* klass, void* iter);
    using get_field_name_t = const char* (APICALL*)(const void* field);

    inline get_field_t get_field = nullptr;
    inline get_field_offset_t get_field_offset = nullptr;
    inline get_field_count_t get_field_count = nullptr;
    inline get_fields_t get_fields = nullptr;
    inline get_field_name_t get_field_name = nullptr;

    using get_method_rva_t = size_t(APICALL*)(const void* method);
    using get_method_t = void* (APICALL*)(const void* klass, const char* name);

    inline get_method_rva_t get_method_rva = nullptr;
    inline get_method_t get_method = nullptr;

    using get_method_name_t = const char* (APICALL*)(const void* method);
    inline get_method_name_t get_method_name = nullptr;

    using get_methods_t = void* (APICALL*)(const void* klass, void* iter);
    using get_method_count_t = size_t(APICALL*)(const void* klass);


    inline get_methods_t get_methods = nullptr;
    inline get_method_count_t get_method_count = nullptr;

    // Required to be called before initalization of the dumper for the rest of the dumper to work properly
    inline void init();
}

#pragma warning(disable : 6387)
void api::init()
{
    if (initalized)
        return;

    get_domain = reinterpret_cast<get_domain_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_domain_get")
        );

    get_assemblies = reinterpret_cast<get_assemblies_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_domain_get_assemblies")
        );

    get_image = reinterpret_cast<get_image_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_assembly_get_image")
        );


    get_image_name = reinterpret_cast<get_image_name_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_image_get_name")
        );

    get_class_count = reinterpret_cast<get_class_count_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_image_get_class_count")
        );

    get_class = reinterpret_cast<get_class_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_from_name")
        );

    get_class_from_id = reinterpret_cast<get_class_from_id_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_image_get_class")
        );

    get_class_name = reinterpret_cast<get_class_name_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_name")
        );

    get_type_name = reinterpret_cast<get_type_name_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_type_get_name")
        );

    get_type_class = reinterpret_cast<get_type_class_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_type_get_class_or_element_class")
        );

    get_field = reinterpret_cast<get_field_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_field_from_name")
        );

    get_field_offset = reinterpret_cast<get_field_offset_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_field_get_offset")
        );

    get_nested_types = reinterpret_cast<get_nested_types_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_nested_types")
        );

    get_field_count = reinterpret_cast<get_field_count_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_num_fields")
        );

    get_fields = reinterpret_cast<get_fields_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_fields")
        );

    get_field_name = reinterpret_cast<get_field_name_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_field_get_name")
        );

    get_method_rva = reinterpret_cast<get_method_rva_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_method_get_token")
        );

    get_method = reinterpret_cast<get_method_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_method_from_name")
        );

    get_method_name = reinterpret_cast<get_method_name_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_method_get_name")
        );

    get_methods = reinterpret_cast<get_methods_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_get_methods")
        );

    get_method_count = reinterpret_cast<get_method_count_t>(
        GetProcAddress(GetModuleHandle("GameAssembly.dll"), "il2cpp_class_num_methods")
        );
}

class Class
{
public:
    using fields_t = std::vector<void*>;
private:
    const char* m_name{};

public:
    Class() = default;

    // Returns a field by name
    template <typename type>
    auto get_field(const char* name) const
    {
        const auto field = api::get_field(this, name);
        if (!field)
            return nullptr;

        const auto offset = api::get_field_offset(field);
        return reinterpret_cast<type>(reinterpret_cast<uintptr_t>(this) + offset);
    }

    // Returns the offset of the field relative to the class
    size_t get_field_offset(const char* name) const
    {
        const auto field = api::get_field(this, name);
        return api::get_field_offset(field);
    }

    // Returns a class nested inside of the current class by name
    auto get_nested_type(const char* name) const -> Class*
    {
        void* iterator = nullptr;
        while (auto type = api::get_nested_types(this, &iterator))
        {
            const auto class_name = api::get_class_name(type);
            if (!strcmp(class_name, name))
                return static_cast<Class*>(type);
        }

        return nullptr;
    }

    // Returns a vector of fields (as void pointers)
    auto get_fields() const -> fields_t
    {
        fields_t m_fields{};
        if (!m_fields.empty())
            return m_fields;

        const auto count = api::get_field_count(this);
        if (count)
            m_fields.resize(count);

        void* iterator = nullptr;
        void* field = nullptr;

        size_t index = 0;
        while ((field = api::get_fields(this, &iterator)))
        {
            if (!field || field == nullptr)
                continue;

            m_fields[index++] = field;
        }

        return m_fields;
    }

    auto get_name() const -> const char* { return api::get_class_name(this); }

    // Returns a method by name
    auto get_method(const char* name) const -> void*
    {
        return api::get_method(this, name);
    }
};
class Image
{
public:
    using classes_t = std::vector<void*>;
private:
    const char* m_name{ };

public:

    // Gets an Il2CppClass from a namespace (global by default) and name
    auto get_class(const char* name, const char* namespaze = "") const -> Class*
    {
        const auto klass = api::get_class(this, namespaze, name);
        return klass;
    }

    // Returns a static vector of Il2CppClasses for that image
    auto get_classes() const -> classes_t
    {
        static classes_t m_classes{ };
        if (m_classes.size())
            return m_classes;

        size_t count = api::get_class_count(this);
        if (count)
            m_classes.resize(count);

        size_t valid_classes = 0;
        for (size_t index = 0U; index < count; ++index)
        {
            auto address = api::get_class_from_id(this, index);
            if (!address)
                continue;

            auto name = api::get_class_name(address);
            if (!name)
                continue;

            if (!strcmp(name, "<Module>"))
                continue;

            m_classes[valid_classes++] = address;
        }
        return m_classes;
    }

    // Returns the image name
    auto get_name() const { return m_name; }
};

class Dumper
{
public:
    using images_t = std::vector<Image*>;
private:
    images_t  m_images{ };

public:

    // Dumps all images on initalization
    Dumper()
    {
        size_t count = 0U;
        const auto domain = api::get_domain();
        const auto assemblies = api::get_assemblies(domain, &count);

        for (size_t index = 0U; index < count; ++index)
        {
            auto image = api::get_image(assemblies[index]);
            if (image)
                m_images.emplace_back(static_cast<Image*>(image));
        }
    };

    // Loop through current image names and checks their names to find a matching image
    auto get_image(const char* name) const -> Image*
    {
        for (const auto image : m_images)
        {
            if (!strcmp(name, image->get_name()))
                return image;
        }
        return nullptr;
    }

    // Returns image table
    auto get_images() const -> images_t { return m_images; }


};

void FindMethodOffsets()
{
    api::init();

    const auto game = std::make_unique<Dumper>();
    const auto image = game->get_image("UnityEngine.CoreModule.dll");

    if (!image)
    {
        printf("Image is Invalid");
        return;
    }

    const auto Klass = image->get_class("Time", "UnityEngine");
    if (!Klass)
    {
        printf("Class is Invalid");
        return;
    }
    
    const auto method = Klass->get_method("UnityEngine_Time__set_timeScale");
    if (!method)
    {
        printf("method is Invalid");
        return;
    }
}
