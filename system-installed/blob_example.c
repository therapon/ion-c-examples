#include <stdio.h>
#include <ionc/ion.h>
#include <stdlib.h>
#include <assert.h>

#define ION_OK(x) if (x) { printf("Error: %s\n", ion_error_to_str(x)); return x; }

int main(int argc, char **argv) {
    const char *ion_text = "{{OiBTIKUgTyAASb8=}}";

    hREADER reader;
    ION_READER_OPTIONS options;

    memset(&options, 0, sizeof(ION_READER_OPTIONS));

    ION_OK(ion_reader_open_buffer(&reader,
                                  (BYTE *)ion_text,
                                  (SIZE)strlen(ion_text),
                                  &options));

    ION_TYPE ion_type;
    ION_OK(ion_reader_next(reader, &ion_type));
    assert(ion_type == tid_BLOB);

    SIZE lob_size;
    ION_OK(ion_reader_get_lob_size(reader, &lob_size));
    printf("Size of blob = %d", lob_size);
}
