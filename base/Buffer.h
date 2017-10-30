#ifndef MYTH52125_BUFFER_H
#define MYTH52125_BUFFER_H

// #include <codebase/net/>
#include <vector>
#include <algorithm>
#include <assert>

namespace myth52125
{
namespace base
{


class Buffer
{
public:
    Buffer(size_t buffer_size = s_buffer_size)
        :mc_buffer(buffer_size+s_buffer_pre_size),
        m_read_start(s_buffer_pre_size),
        m_write_start(s_buffer_pre_size)
    {

    }

private:
    std::vector<char> mc_bufer;
    size_t m_read_start;
    size_t m_write_start;
    void enable_write(size_t len);
    void make_space(size_t len)
    {
        if(enable_write_size() + m_read_start < len+s_buffer_pre_size)
        {
            mc_bufer.resize(len+s_buffer_pre_size)
        }else{
            std::copy(&*mc_bufer.begin()+m_read_start,&*mc_bufer.begin()+m_write_start,
            &*mc_bufer.begin()+s_buffer_pre_size);
        }
    }

    void enable_write(size_t len)
    {

        if(enable_write_size() < len)
        {
            make_space(len);
        }

        assert(enable_write_size()>=len);
    }

public:
    static size_t s_buffer_size;
    static size_t s_buffer_pre_size;
    static const char s_crlf[];
    
    size_t store_size()
    {   return m_write_start-m_read_start;  }

    size_t enable_write_size()
    {   return mc_bufer.size()-m_write_start;   }

    const char *read_start_p()
    {   return &*mc_bufer.begin()+m_read_start; }
    
    const char *write_start_p()
    {   return &*mc_bufer.begin()+m_write_start;    }

    const char find_crlf()
    {
        const char *crlf = std::search(read_start_p(),write_start_p,
                                        s_crlf,s_crlf+2);
        return crlf == write_start_p() ? NULL : crlf; 
    }

    void top_data(void *buf,size_t len)
    {
        memcpy(buf,read_start_p(),len);
    }

    void read_data(void *buf,size_t len)
    {
        assert(len >= store_size());
        top_data(buf,len);
        m_read_start+=len;
    }
    
    void prepend(const void *buf,size_t len)
    {
        assert(len <= store_size());
        m_read_start -= len;
        std::copy(buf,read_start_p(),len);
    }
    
    void append(const void *buf,size_t len)
    {
        enable_write(len);
        std::copy(buf,buf+len,write_start_p());
    }

};
}

}

#endif  //MYTH52125_BUFFER_H