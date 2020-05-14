#include <stdio.h>
#include <ionc/ion.h>
#include <malloc.h>

#define ION_OK(x) if (x) { printf("Error: %s\n", ion_error_to_str(x)); return x; }

int main(int argc, char **argv) {
    const char* ion_text = "{hello: \"world\"}";


    hREADER reader;
    ION_READER_OPTIONS options;

    memset(&options, 0, sizeof(ION_READER_OPTIONS));

    ION_OK(ion_reader_open_buffer(&reader,
                                  (BYTE *)ion_text,
                                  (SIZE)strlen(ion_text),
                                  &options));

    ION_TYPE ion_type;
    ION_OK(ion_reader_next(reader, &ion_type));     // position the reader at the first value, a struct
    ION_OK(ion_reader_step_in(reader));             // step into the struct
    ION_OK(ion_reader_next(reader, &ion_type));     // position the reader at the first value in the struct

    ION_STRING ion_string;
    ION_OK(ion_reader_get_field_name(reader, &ion_string));  // retrieve the current value's field name
    char *field_name = ion_string_strdup(&ion_string);

    ION_OK(ion_reader_read_string(reader, &ion_string));     // retrieve the current value's string value
    char *value = ion_string_strdup(&ion_string);

    ION_OK(ion_reader_step_out(reader));            // step out of the struct
    ION_OK(ion_reader_close(reader));               // close the reader

    printf("%s %s\n", field_name, value);           // prints:  hello world
    free(value);
    free(field_name);
    return 0;
}