/*
 * tio.cc
 *
 * Ian Soboroff, NIST
 * June, 1994
 *
 * Usage: tio infile [outfile]
 *
 * tio tests reading, writing, and appending of STEPfiles.  It must be given
 * a STEPfile for input, and will write output to stdout.  It reads the input
 * file, writes it to stdout, appends another copy of the input file to the
 * instances already in memory, prints all the instances out via the registry,
 * and then writes the final STEPfile to stdout and to the optional output
 * file.
 */

/* A switch for tests.h, because we don't need to schema header file */
#define DONT_NEED_HEADER
#include "tests.h"

int main(int argc, char *argv[])
{
    int using_outfile = 0;

    if(argc > 3 || argc < 2) {
        cout << "Syntax:   tio infile [outfile]" << endl;
        exit(1);
    } else if(argc > 2) {
        using_outfile = 1;    // output filename is in argv[2]
    }

    // if the comments below look canned, it's because they're taken
    // straight from the treg source... ;-)

    // This has to be done before anything else.  This initializes
    // all of the registry information for the schema you are using.
    // The SchemaInit() function is generated by exp2cxx... see
    // extern statement above.

    Registry *registry = new Registry(SchemaInit);

    // The nifty thing about the Registry is that it basically keeps a list
    // of everything in your schema.  What this means is that we can go
    // through the Registry and instantiate, say, one of everything, without
    // knowing at coding-time what entities there are to instantiate.  So,
    // this test could be linked with other class libraries produced from
    // other schema, rather than the example, and run happily.

    InstMgr instance_list;
    STEPfile *sfile = new STEPfile(*registry, instance_list);

    // The STEPfile is actually an object that manages the relationship
    // between what's instantiated in the instance manager, and how that
    // information gets passed to the outside, e.g., a file on disk.

    // First we're going to read in the data from the input STEPfile,
    // and print it to stdout

    // Reading the STEPfile instantiates all the objects in it.
    // The instances get pointers into the InstMgr, and each type
    // and entity gets a pointer into the registry.
    cout << "\n### Reading exchange file from " << argv[1] << endl;
    sfile->ReadExchangeFile(argv[1]);

    // Just checking... ;-)
    cout << "\n### The InstMgr says there are ";
    cout << instance_list.InstanceCount() << " instantiated objects" << endl;

    cout << "\n### Here is the exchange file:" << endl << endl;
    sfile->WriteExchangeFile(cout);

    // If you append in another exchange file, it creates new instances
    // starting at a 1000-block of numbers.  Just 'Read'ing again
    // would clobber the instances already there.
    cout << "\n### Now appending in another copy" << endl;
    sfile->AppendExchangeFile(argv[1]);

    // Browsing the registry...
    cout << "\n### Here is a list of entities now in the registry:" << endl;
    registry->ResetEntities();
    const EntityDescriptor *ent = registry->NextEntity();
    std::string tmpstr;
    while(ent) {
        cout << ent->Name() << ": " << ent->TypeString(tmpstr) << endl;
        ent = registry->NextEntity();
    }

    // Browsing through the instance manager.  This shows how to get
    // at those instances it points to.
    cout << "\n### And here are all the instantiated objects..." << endl;
    int numInstances = instance_list.InstanceCount();
    cout << "### The InstMgr says we have " << numInstances;
    cout << " things instantiated.\n";
    for(int i = 0; i < numInstances; i++) {
        cout << i << ": " << instance_list.GetSTEPentity(i)->EntityName();
        cout << " (" <<
             instance_list.GetSTEPentity(i)->eDesc->Description();
        cout << ")" << endl;
    }

    // Dump everything to STEPfiles...
    cout << "\n### Here it is in STEPfile format:" << endl << endl;
    sfile->WriteExchangeFile(cout);

    if(using_outfile) {
        ofstream stepout(argv[2]);
        cout << "\n### Writing that to outfile " << argv[2] << endl;
        sfile->WriteExchangeFile(stepout);
    }
    exit(0);
}

